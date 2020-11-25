import socket
import sys
import json

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = 'localhost'
port = 8003

s.connect((host, port))
data = s.recv(1024)
data = data.decode("utf-8")

s.send(b'Thank you from client')

dataj = json.loads(data)
print(type(dataj))
print(dataj)

s.close()
