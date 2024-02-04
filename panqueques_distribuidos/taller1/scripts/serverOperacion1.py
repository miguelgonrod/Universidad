#!/usr/bin/env python3

import socket

class operationSocket():
    def __init__(self):
        self.HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
        self.PORT = 65433  # Port to listen on (non-privileged ports are > 1023)
    
    def calcOperation(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.bind((self.HOST, self.PORT))   # open a socket
            while True:
                s.listen()                   # Wait a message send from the socket
                conn, addr = s.accept()      # saves the client socket connection and the connection ip addess respectively
                with conn:
                    print(f"Connected by {addr}")
                    data = conn.recv(1024)     # receives the operation
                    if data:
                        resultado = eval(data)     # converts an string to an operation and calculates it
                        print(resultado)
                        conn.sendall(str(resultado).encode('utf-8'))   # sends an answer to the connected calculus server

if __name__ == "__main__":
    mysocket = operationSocket()
    mysocket.calcOperation()