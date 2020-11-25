import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
port = 8000

s.connect(('localhost', port))

data = s.recv(1024)
s.send(b'Connection from client here')

print(data)
s.close()

