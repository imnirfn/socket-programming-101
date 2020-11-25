import socket
import os
from _thread import *

def threaded_client(conn):
    conn.send(str.encode("Welcome to the server!\n"))
    while True:
        data = conn.recv(2048)
        reply = 'Server says ' + data.decode('utf-8')
        
        if not data:
            break
        conn.sendall(str.encode(reply))
    conn.close()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = ''
port = 8002
thread_count = 0

try:
    s.bind((host, port))
except socket.error as e:
    print("Error here: ", str(e))

print("Waiting for connection..")
s.listen(5)

while True:
    client, addr = s.accept()
    print("Connected to " + addr[0] + ":" + str(addr[1]))
    start_new_thread(threaded_client, (client,))
    thread_count += 1
    print("Thread number: " + str(thread_count))

s.close()











