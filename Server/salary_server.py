import socket
from pymongo import MongoClient
from server.operations import *

if __name__ == '__main__':
    mongo_client = MongoClient(host='127.0.0.1', port=27017)

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
                ret_msg = login(mongo_client, js['data'])
            elif js['op'] == 'query_sala':
                ret_msg = query_salary(mongo_client, js['data'])
            elif js['op'] == 'change_pass':
                ret_msg = change_pass(mongo_client, js['data'])
            elif js['op'] == 'query_info':
                ret_msg = query_info(mongo_client, js['data'])
            elif js['op'] == 'admin_login':
                ret_msg = admin_login(mongo_client, js['data'])
            elif js['op'] == 'reset_pass':
                ret_msg = reset_pass(mongo_client, js['data'])
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
