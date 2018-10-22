#include "operation.h"

sockaddr make_sockaddr(const char *name, int port)
{
    sockaddr_in addr;
    addr.sin_addr.s_addr = inet_addr(name);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    bzero(addr.sin_zero, sizeof(addr.sin_zero));

    return *(sockaddr*)&addr;
}

std::string doc_to_string(Document &doc)
{
    StringBuffer buf;
    Writer<StringBuffer> writer(buf);
    doc.Accept(writer);
    std::string json = buf.GetString();
    return json;
}

std::string get_md5(const QString &data)
{
    return QCryptographicHash::hash(data.toUtf8(), QCryptographicHash::Md5)
            .toHex().toStdString();
}

ErrNo login(const QString &id, const QString &pass)
{
    // 构建json
    Document doc;
    doc.SetObject();
    // operation为登陆操作
    Document::AllocatorType &alloc = doc.GetAllocator();
    doc.AddMember("op", "login", alloc);
    doc.AddMember("data", kObjectType, alloc);
    Value &data_v = doc["data"];
    // 添加字符串是真的麻烦
    data_v.AddMember("id", Value(id.toStdString().c_str(), alloc).Move(), alloc);
    // 获取密码的md5摘要
//    qDebug() << pass << "\n";
    auto hash = get_md5(pass);
//    qDebug() << hash << "\n";
    data_v.AddMember("pass", Value(hash.c_str(), alloc).Move(), alloc);
    // 获取json
    std::string data = doc_to_string(doc);
    // 准备连接服务器
    sockaddr server = make_sockaddr(HOST, PORT);
    // 获取一个socket描述符
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    qDebug() << data.c_str();
    // 尝试连接
    if (::connect(sock, &server, sizeof(server)) == 0) {
        send(sock, data.c_str(), data.length(), 0);
        char buf[BUF_SIZE];
        long len = read(sock, buf, BUF_SIZE);
        if (len <  0) {
            return NETWORK_ERR;
        }
        buf[len] = '\0';
        qDebug() << buf;
        // 直接丢弃原来的内容
        doc.SetObject();
        // 获取返回的信息
        doc.Parse(buf);
        if (doc["status"].GetInt() == 0) {
            return OK;
        } else {
            return NAME_PASS_ERR;
        }
    }
    return NETWORK_ERR;
}

ErrNo query_salary(const QDate &start, const QDate &end, const QString &id, std::vector<Salary> &result)
{
    Document doc;
    doc.SetObject();
    Document::AllocatorType &alloc = doc.GetAllocator();
    doc.AddMember("op", "query_sala", alloc);
    doc.AddMember("data", kObjectType, alloc);
    Value &data_v = doc["data"];
    data_v.AddMember("start_year", start.year(), alloc);
    data_v.AddMember("start_month", start.month(), alloc);
    data_v.AddMember("end_year", end.year(), alloc);
    data_v.AddMember("end_month", end.month(), alloc);
    data_v.AddMember("id", Value(id.toStdString().c_str(), alloc).Move(), alloc);

    std::string json = doc_to_string(doc);

    sockaddr server = make_sockaddr(HOST, PORT);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // 一般来说申请socket是不会被拒绝的
    if (connect(sock, &server, sizeof(server)) == 0) {
        // 发送请求和数据
        long len = send(sock, json.c_str(), json.size(), 0);
        if (len < 0) {
            // 发送失败
            return NETWORK_ERR;
        }
        json.clear();
        char buf[BUF_SIZE];
        while ((len = read(sock, buf, BUF_SIZE)) > 0) {
            buf[len] = '\0';
            qDebug() << buf;
            json.append(buf, len);
        }
        if (json.length() == 0) {
            close(sock);
            return NETWORK_ERR;
        }
        doc.SetObject();
        doc.Parse(json.c_str());
        // 解析传回来的数据
        // 返回的应该包含
        int status = doc["status"].GetInt();
        if (status != 0) {
            // 错误码与这里面的相同
            return ErrNo(status);
        }
        qDebug() << "status: " << status;
        Value &arr_v = doc["data"];
        assert(arr_v.IsArray());
        Salary sala;
        for (int i = 0; i < arr_v.Size(); ++i) {
            Value &sala_v = arr_v[i];
            sala.year = sala_v["year"].GetInt();
            sala.month = sala_v["month"].GetInt();
            sala.base = sala_v["base"].GetInt();
            sala.bonus = sala_v["bonus"].GetInt();
            sala.fine = sala_v["fine"].GetInt();
            // 最终工资直接自己计算吧，不麻烦服务器了
            sala.salary = sala.base + sala.bonus - sala.fine;
            result.push_back(sala);
        }
        // 感谢服务器，关闭连接结束
        qDebug() << "close socket";
        close(sock);
        return OK;
    }
    // 连接失败
    close(sock);
    return NETWORK_ERR;
}

ErrNo change_pass(const QString &id, const QString &old_pass, const QString &new_pass)
{
    Document doc;
    doc.SetObject();
    Document::AllocatorType &alloc = doc.GetAllocator();
    doc.AddMember("op", "change_pass", alloc); // 加入操作数据
    doc.AddMember("data", kObjectType, alloc);
    Value &data_v = doc["data"];
    data_v.AddMember("id", Value(id.toStdString().c_str(), alloc).Move(), alloc);
    data_v.AddMember("old_pass", Value(get_md5(old_pass).c_str(), alloc).Move(), alloc);
    data_v.AddMember("new_pass", Value(get_md5(new_pass).c_str(), alloc).Move(), alloc);
    std::string json = doc_to_string(doc);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr server_addr = make_sockaddr(HOST, PORT);
    // 尝试发送数据
    if (connect(sock, &server_addr, sizeof(server_addr)) == 0) {
        send(sock, json.c_str(), json.size(), 0);
        // 接收数据试一下
        char buf[BUF_SIZE];
        long len = 0;
        json.clear();
        while ((len = read(sock, buf, BUF_SIZE)) > 0) {
            json.append(buf, len);
        }
        doc.SetObject();
        // 解析返回的数据
        doc.Parse(json.c_str());
        // 解析状态码
        int status = doc["status"].GetInt();
        if (status == OK) {
            return OK;
        }
        return ErrNo(status);
    }
    // 连接不上，关闭套接字，返回错误
    close(sock);
    return NETWORK_ERR;
}

ErrNo query_info(const QString &id, User &user)
{
    Document doc;
    doc.SetObject();
    Document::AllocatorType &alloc = doc.GetAllocator();
    doc.AddMember("op", "query_info", alloc);
    doc.AddMember("data", kObjectType, alloc);
    Value &data_v = doc["data"];
    data_v.AddMember("id", Value(id.toStdString().c_str(), alloc).Move(), alloc);
    std::string json = doc_to_string(doc);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr server_addr = make_sockaddr(HOST, PORT);
    // 连接服务器，发送数据
    if (connect(sock, &server_addr, sizeof(server_addr)) == 0) {
        send(sock, json.c_str(), json.size(), 0);
        int len = 0;
        json.clear();
        char buf[BUF_SIZE];
        while ((len = read(sock, buf, BUF_SIZE)) > 0) {
            json.append(buf, len);
        }
        qDebug() << json.c_str();
        doc.SetObject();
        doc.Parse(json.c_str());
        int status = doc["status"].GetInt();
        if (status == OK) {
            Value &user_v = doc["data"];
            user.name = user_v["name"].GetString();
            user.id = user_v["id"].GetString();
            user.section = user_v["section"].GetString();
            user.contact = user_v["contact"].GetString();
            user.age = user_v["age"].GetInt();
            user.position = user_v["position"].GetString();
            return OK;
        }
        return ErrNo(status);
    }
    close(sock);
    return NETWORK_ERR;
}

ErrNo admin_login(const QString &id, const QString &pass)
{
    // 管理员登陆
    Document doc;
    Document::AllocatorType &alloc = doc.GetAllocator();
    doc.SetObject();
    doc.AddMember("op", "admin_login", alloc);
    doc.AddMember("data", kObjectType, alloc);
    Value &data_v = doc["data"];
    data_v.AddMember("id", Value(id.toStdString().c_str(), alloc).Move(), alloc);
    auto hash = get_md5(pass);
//    qDebug() << hash << "\n";
    data_v.AddMember("pass", Value(hash.c_str(), alloc).Move(), alloc);
    // 获取json
    std::string data = doc_to_string(doc);
    // 准备连接服务器
    sockaddr server = make_sockaddr(HOST, PORT);
    // 获取一个socket描述符
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    qDebug() << data.c_str();
    // 尝试连接
    if (::connect(sock, &server, sizeof(server)) == 0) {
        send(sock, data.c_str(), data.length(), 0);
        char buf[BUF_SIZE];
        long len = read(sock, buf, BUF_SIZE);
        if (len <  0) {
            return NETWORK_ERR;
        }
        buf[len] = '\0';
        qDebug() << buf;
        // 直接丢弃原来的内容
        doc.SetObject();
        // 获取返回的信息
        doc.Parse(buf);
        if (doc["status"].GetInt() == 0) {
            return OK;
        } else {
            return ErrNo(doc["status"].GetInt());
        }
    }
    return NETWORK_ERR;
}

ErrNo reset_pass(const QString &id, const QString &pass)
{
    Document doc;
    doc.SetObject();
    Document::AllocatorType &alloc = doc.GetAllocator();
    doc.AddMember("op", "reset_pass", alloc);
    doc.AddMember("data", kObjectType, alloc);
    Value &data_v = doc["data"];
    data_v.AddMember("id", Value(id.toStdString().c_str(), alloc).Move(), alloc);
    auto hash = get_md5(pass);
    data_v.AddMember("pass", Value(hash.c_str(), alloc).Move(), alloc);
    std::string json = doc_to_string(doc);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr server = make_sockaddr(HOST, PORT);

    if (connect(sock, &server, sizeof(server)) == 0) {
        send(sock, json.c_str(), json.size(), 0);
        json.clear();
        int len;
        char buf[BUF_SIZE];
        while ((len = recv(sock, buf, BUF_SIZE, 0)) > 0) {
            json.append(buf, len);
        }
        doc.SetObject();
        doc.Parse(json.c_str());
        int status = doc["status"].GetInt();
        return ErrNo(status);
    }
    return NETWORK_ERR;
}
