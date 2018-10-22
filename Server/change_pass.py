from pymongo import MongoClient
import json


def change_pass(data):
    mongo_client = MongoClient()
    db = mongo_client['salary_manage']
    user_pass = db['user_pass']

    if user_pass.count_documents(filter={'id': {'$eq': data['id']}}) == 0:
        ret_msg = {'status': 1}
    else:
        record = user_pass.find_one(filter={'id': {'$eq': data['id']}})
        if data['old_pass'] == record['pass']:
            user_pass.find_one_and_update(filter={'id': {'$eq': data['id']}},
                                          update={'$set': {'pass': data['new_pass']}})
            ret_msg = {'status': 0}
        else:
            ret_msg = {'status': 4}
    print(ret_msg)
    return json.dumps(ret_msg)


if __name__ == '__main__':
    change_pass({'id': 'yaning', 'old_pass': '81dc9bdb52d04dc20036dbd8313ed055',
                 'new_pass': '81dc9bdb52d04dc20036dbd8313ed055'})
