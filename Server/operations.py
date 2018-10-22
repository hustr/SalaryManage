import json
import pymongo

OK = 0
NETWORK_ERR = 1
NAME_PASS_ERR = 2
INFO_ERR = 3
UNKNOWN_ERR = 4
NO_USER = 5


def login(mongo, data):
    name, _pass = data['id'], data['pass']
    db = mongo['salary_manage']
    user_pass = db['user_pass']
    result = user_pass.find_one(filter={'id': {'$eq': name}})
    print(result)
    if result and result['pass'] == _pass:
        ret_msg = {'status': OK}
    else:
        ret_msg = {'status': NAME_PASS_ERR}
    return json.dumps(ret_msg)


def query_salary(mongo, data):
    start_year = data['start_year']
    start_mon = data['start_month']
    end_year = data['end_year']
    end_mon = data['end_month']
    _id = data['id']
    db = mongo['salary_manage']
    salary_coll = db['salary']
    # 转换成一个整数来查询，比较容易实现
    st = start_year * 100 + start_mon
    ed = end_year * 100 + end_mon
    print(f'start: {st}, end: {ed}')
    user_pass = db['user_pass']
    ret_msg = {'status': UNKNOWN_ERR}
    if user_pass.count_documents(filter={'id': {'$eq': _id}}) == 0:
        ret_msg['status'] = NO_USER
        return json.dumps(ret_msg)

    salaries = salary_coll.find(filter={'id': {'$eq': _id},
                                        '$and': [{'date': {'$gte': st}},
                                                 {'date': {'$lte': ed}}]})
    result = []
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


def change_pass(mongo, data):
    db = mongo['salary_manage']
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


def query_info(mongo, data):
    db = mongo['salary_manage']
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


def admin_login(mongo, data):
    _id, _pass = data['id'], data['pass']
    # 先检测此人账户是否是管理员账户
    db = mongo['salary_manage']
    admin_all = db['admin']
    ret_msg = {'status': NO_USER}
    if admin_all.count_documents(filter={'id': {'$eq': _id}}) != 0:
        user_pass = db['user_pass']
        # 如果在admin里面找到了此人，一定在user_pass里也有
        record = user_pass.find_one(filter={'id': {'$eq': _id}})
        print(record)
        if record['pass'] == _pass:
            ret_msg['status'] = OK
        else:
            ret_msg['status'] = NAME_PASS_ERR
    return json.dumps(ret_msg)


def reset_pass(mongo: pymongo.MongoClient, data):
    db = mongo['salary_manage']
    user_pass = db['user_pass']
    _id = data['id']
    _pass = data['pass']

    if user_pass.count_documents(filter={'id': {'$eq': _id}}) != 0:
        ret_msg = {'status': OK}
        user_pass.find_one_and_update(filter={'id': {'$eq': _id}},
                                      update={'$set': {'pass': _pass}})
    else:
        ret_msg = {'status': NO_USER}

    return json.dumps(ret_msg)
