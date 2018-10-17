#include "operation.h"

ErrNo login(const QString &name, const QString &pass)
{
    // 设置数据使用的指针
    static Pointer op("/op");
    static Pointer data_name("/data/name");
    static Pointer data_pass_hash("/data/pass");
    // 构建json
    Document doc;
    doc.SetObject();
    // operation为登陆操作
    op.Set(doc, "login");
    data_name.Set(doc, name.toStdString().c_str());
    // 获取密码的md5摘要
    QByteArray hash = QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Md5).toHex();
    data_pass_hash.Set(doc, hash.toStdString().c_str());
    // 获取json
    StringBuffer buf;
    Writer<StringBuffer> writer(buf);
    doc.Accept(writer);
    std::string data = buf.GetString();
    // 准备连接服务器
    sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_port = htons(PORT);
    server.sin_family = AF_INET;
    bzero(server.sin_zero, sizeof(server.sin_zero));
    // 获取一个socket描述符
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    qDebug() << data.c_str();
    // 尝试连接
    if (::connect(sock, (sockaddr*)&server, sizeof(server)) == 0) {
        send(sock, data.c_str(), data.length(), 0);
        char buf[65536];
        int len = read(sock, buf, 65536);
        buf[len] = '\0';
        qDebug() << buf;
        Document d;
        d.Parse(buf);
        if (d["status"].GetInt() == 0) {
            return OK;
        } else {
            return NAME_PASS_ERR;
        }
    }
    return NETWORK_ERR;
}
