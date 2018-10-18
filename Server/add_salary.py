from collections import namedtuple

from pymongo import MongoClient

Salary = namedtuple('Salary', ['year', 'month', 'base', 'bonus', 'fine'])


def add_salary(_id, salary):
    year = salary[0]
    mon = salary[1]
    date = year * 100 + mon
    client = MongoClient(host='127.0.0.1', port=27017)
    db = client['salary_manage']
    coll = db['salary']
    if coll.count_documents(filter={'id': {'$eq': _id},
                                    'date': {'$eq': date}}) == 0:
        print(f'insert {_id} {date}')
        coll.insert_one({'id': _id, 'date': date,
                         'base': salary[2], 'bonus': salary[3],
                         'fine': salary[4]})


if __name__ == '__main__':
    add_salary('yaning', Salary(2018, 8, 3000, 200, 0))
    add_salary('yaning', Salary(2018, 7, 3000, 300, 20))
    pass
