import socket
import os
import sys

def upload(file_name):
    print("dadsa")

if __name__ == "__main__":

    HOST = 'localhost'
    PORT = 8005
    BUFFER = 2048

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        s.connect((HOST, PORT))
    except socker.error as e:
        print("Error here: " + str(e))

    print("Welcome to Devhouze's FTP client\n")

    while True:
        inp, file = input("cli > ").split()
        if inp == "upload":
            upload(file)

    s.close()
