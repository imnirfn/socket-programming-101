import socket
import os
import sys

def upload():
    print("Hi\n")

if __name__ == "__main__":

    HOST = 'localhost'
    PORT = 8005
    BUFFER = 2048

    print("Welcome to Devhouze's FTP server\n")
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        s.bind((HOST, PORT))
    except socket.error as e:
        print("Socket error: " + str(e))

    s.listen(5)
    client, addr = s.accept()
    print("Connected from " + str(addr))

    while True:
        client.send(b'Connected')
        data = client.recv(BUFFER)

        if data == 'upload':
            upload()
        data = None
    client.close()





