from pymongo import MongoClient
import hashlib


def get_md5(s):
    md5 = hashlib.md5()
    md5.update(s.encode('utf8'))
    return md5.hexdigest()


def add_user(name, _pass):
    client = MongoClient(host="127.0.0.1", port=27017)
    db = client['salary_manage']
    # 记录用户名和密码
    user_pass = db['user_pass']
    if user_pass.count_documents(filter={'name': {'$eq': name}}) != 0:
        return False
    user_pass.insert_one({'name': name, 'pass': get_md5(_pass)})
    return True


if __name__ == '__main__':
    print(add_user('yaning', 'abcd'))
    pass
