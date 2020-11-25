import socket
import json
import sys

data = {
    "id": 1234,
    "name": "s3ns3",
    "age": 40
}
send_data = json.dumps(data)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = ''
port = 8003

s.bind((host, port))
print("Socket binded to " + str(port))
s.listen(5)

while True:
    c, addr = s.accept()
    print("Connection from " + str(addr))
    c.sendall(bytes(send_data, encoding="utf-8"))

    buffer = c.recv(1024)
    print(buffer)

c.close()
