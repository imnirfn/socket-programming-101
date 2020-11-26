import socket
import os
import sys

def upload(file_name):
    print("Uploading file to server..")

    # check if file exists
    try:
        data = open(file_name, "rb")
    except:
        print("Couldnt open file")
        return
    
    # check connection with server
    try:
        s.send(b'upload')
    except socket.error as e:
        print("Connection error: " + str(e))
        return


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
        inp = input("cli > ").split()
        if inp == "upload":
            upload(file)

    s.close()
