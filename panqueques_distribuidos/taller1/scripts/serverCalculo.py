#!/usr/bin/env python3

import socket
import random

class calcSocket:
    def __init__(self):
        self.MYIP = socket.gethostbyname(socket.gethostname())
        self.MYPORT = 65430  # Port to listen on (non-privileged ports are > 1023)
        self.HOSTIP = ("172.20.0.5","172.20.0.2")
        self.HOSTPORT = 65433  # Ports to the operation servers
        self.servidorNumber = 1         # which server are we going to send the operation
    
    def sendQuery(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.bind((self.MYIP, self.MYPORT))   # opens a socket
            while True:
                s.listen()                     # Wait a message send from the socket
                conn, addr = s.accept()        # saves the client socket connection and the connection ip addess respectively
                with conn:
                    print(f"Connected by {addr}")
                    data = conn.recv(1024)     # receives the operation
                    print(data)
                    if data:
                        data = self.checkServers(data)

                        conn.sendall(data)      # sends an answer to the connected client
    
    def checkServers(self, data: str) -> bytes:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as h:
            self.servidorNumber = random.randint(0,1)                       # get a message of which server are we going to send the operation
            try:                                                            # try to connect the gotten server
                h.connect((self.HOSTIP[self.servidorNumber], self.HOSTPORT))  # connect to the respective operation server
                h.sendall(data)                                             # sends the operation
                data = h.recv(1024)                                         # get the operation result
            except:
                try:
                    h.connect((self.HOSTIP[not self.servidorNumber], self.HOSTPORT))   # it negates the value to try to connect to the alternate server
                    h.sendall(data)                                                  # sends the operation
                    data = h.recv(1024)                                              # get the operation result
                except:                                                              # if if none of the servers are available the calculus server calculate the answer
                    data = eval(data)                                                # converts an string to an operation and calculates it
                    data = str(data).encode('utf-8')                                 # encodes the string to utf-8 bytes to allow the socket to send it
        
        return data

if __name__ == "__main__":
    mysocket = calcSocket()
    mysocket.sendQuery()