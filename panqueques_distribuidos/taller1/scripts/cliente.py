#!/usr/bin/env python3

import socket

class clientSocket:
    def __init__(self):
        self.HOST = "172.20.0.4"  # The server's hostname or IP address
        self.PORT = 65430  # The port used by the server

    def getOperation(self): 
        numero, operacion = "",""
        while True:  
            while numero.isnumeric() or numero == "":
                numero = input("ingrese un numero: ")
                if numero.isnumeric():
                    operacion += numero
                    operacion += "+"

            operacion = operacion[:-1]  # removes the last "+" sign
            
            self.sendQuery(operacion)
            
            numero, operacion = "", ""    # clears the operation
    
    def sendQuery(self, operacion: str):
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                try:
                    s.connect((self.HOST, self.PORT))                           # tries to connect to the socket
                    s.sendall(operacion.encode('utf-8'))                        # sends the operation
                    print("conectado")
                    data = s.recv(1024)                                         # receives the result
                    print(f"Received {data!r}")
            
                except:
                    print("No se pudo conectar al servidor")

            
if __name__ == "__main__":
    mysocket = clientSocket()
    mysocket.getOperation()