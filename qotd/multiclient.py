#!/usr/bin/env python3

import socket

class client(object):
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.connect((self.host, self.port))

    def listenToServer(self):
        while True:
            res = self.socket.recv(1024)
            if(res):
                print(res.decode('utf-8'))

if __name__ == '__main__':
    try:
        conn = client('0.0.0.0', 17)
        conn.listenToServer()
    except socket.error as e:
        print("Error here: ", str(e))


