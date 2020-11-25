import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
port = 8000

s.bind(('', port))
print("Bind success on port ", str(port))
s.listen(5)
print("Waiting for socket..")

while True:
    c, addr = s.accept()
    print("Client connected : " + str(addr))

    c.send(b'Connected')
    buffer = c.recv(1024)
    print(buffer)
c.close()
