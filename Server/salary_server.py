import socket
import json
from pymongo import MongoClient

OK = 0
NETWORK_ERR = 1
NAME_PASS_ERR = 2
INFO_ERR = 3
UNKNOWN_ERR = 4
NO_USER = 5

mongo_client = MongoClient(host='127.0.0.1', port=27017)


def login(data):
    name, _pass = data['name'], data['pass']
    db = mongo_client['salary_manage']
    user_pass = db['user_pass']
    result = user_pass.find_one(filter={'id': {'$eq': name}})
    print(result)
    if result and result['pass'] == _pass:
        ret_msg = {'status': OK}
    else:
        ret_msg = {'status': NAME_PASS_ERR}
    return json.dumps(ret_msg)


def query_salary(data):
    start_year = data['start_year']
    start_mon = data['start_month']
    end_year = data['end_year']
    end_mon = data['end_month']
    _id = data['id']
    db = mongo_client['salary_manage']
    salary_coll = db['salary']
    # 转换成一个整数来查询，比较容易实现
    st = start_year * 100 + start_mon
    ed = end_year * 100 + end_mon
    print(f'start: {st}, end: {ed}')
    salaries = salary_coll.find(filter={'id': {'$eq': _id},
                                        '$and': [{'date': {'$gte': st}},
                                                 {'date': {'$lte': ed}}]})
    result = []
    ret_msg = {'status': UNKNOWN_ERR}
    if salaries:
        for record in salaries:
            item = {}
            item['year'] = record['date'] // 100
            item['month'] = record['date'] % 100
            item['base'] = record['base']
            item['bonus'] = record['bonus']
            item['fine'] = record['fine']
            result.append(item)
        ret_msg['status'] = OK
        ret_msg['data'] = result
    return json.dumps(ret_msg)


def change_pass(data):
    db = mongo_client['salary_manage']
    user_pass = db['user_pass']

    if user_pass.count_documents(filter={'id': {'$eq': data['id']}}) == 0:
        ret_msg = {'status': NO_USER}
    else:
        record = user_pass.find_one(filter={'id': {'$eq': data['id']}})
        if data['old_pass'] == record['pass']:
            user_pass.find_one_and_update(filter={'id': {'$eq': data['id']}},
                                          update={'$set': {'pass': data['new_pass']}})
            ret_msg = {'status': OK}
        else:
            ret_msg = {'status': NAME_PASS_ERR}
    return json.dumps(ret_msg)


def query_info(data):
    db = mongo_client['salary_manage']
    info_coll = db['user_info']
    _id = data['id']
    record = info_coll.find_one(filter={'id': {'$eq': _id}})
    ret_msg = {'status': NO_USER}
    if record is not None:
        # name id contact section age
        ret_msg['status'] = OK
        user = {}
        user['name'] = record['name']
        user['id'] = record['id']
        user['contact'] = record['contact']
        user['section'] = record['section']
        user['age'] = record['age']
        user['position'] = record['position']
        ret_msg['data'] = user
    return json.dumps(ret_msg)


if __name__ == '__main__':
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    server.bind(('0.0.0.0', 2333))
    server.listen(10)
    while True:
        try:
            client, address = server.accept()
            print(f"connection from {address}")
            msg = str(client.recv(10240, 0), 'utf8')
            js = json.loads(msg)
            ret_msg = json.dumps({'status': UNKNOWN_ERR})
            print(msg)
            if js['op'] == 'login':
                ret_msg = login(js['data'])
            elif js['op'] == 'query_sala':
                ret_msg = query_salary(js['data'])
            elif js['op'] == 'change_pass':
                ret_msg = change_pass(js['data'])
            elif js['op'] == 'query_info':
                ret_msg = query_info(js['data'])
            print(ret_msg)
            client.send(ret_msg.encode('utf8'))
            print('send', address, ret_msg)
            client.close()
        except Exception as e:
            print(e)
            client.close()
            server.close()
            break
    server.close()
