import socket
import os
from _thread import *

def threaded_client(conn):
    conn.send(str.encode("Welcome to the server!\n"))
    while True:
        data = conn.recv(2048)
        reply = "[SERVER] " + data.decode('UTF-8')
        
        if not data:
            break
        conn.sendall(str.encode(reply))
    conn.close()

if __name__ =="__main":
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = 'localhost'
    port = 8000
    thread_count = 0

    try:
        s.bind((host, port))
    except socket.error as e:
        print(str(e))

    print("Waiting for connection..")
    s.listen(5)










