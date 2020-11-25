import socket

s = socket.socket()
host = 'localhost'
port = 8001

try:
    s.connect((host, port))
except socket.error as e:
    print("Error here: ", str(e))

resp = s.recv(1024)
print(str(resp))

while True:
    inp = input('Say something: ')
    s.send(str.encode(inp))
    resp = s.recv(1024)
    print(resp.decode('utf-8'))

s.close()


