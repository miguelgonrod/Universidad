CREATE TABLE Productos(
    fabricante VARCHAR2(1),
    modelo VARCHAR2(4),
    tipo VARCHAR2(7),
    CONSTRAINT Productos_PK PRIMARY KEY (modelo)
);

CREATE TABLE PC(
    modelo VARCHAR2(4),
    velocidad FLOAT,
    RAM VARCHAR2(4),
    HD VARCHAR2(3),
    CDD VARCHAR2(3),
    Precio INT,
    CONSTRAINT PC_PK PRIMARY KEY (modelo),
    CONSTRAINT PC_Productos_FK FOREIGN KEY (modelo) REFERENCES Productos(modelo)
);

CREATE TABLE Portatiles(
    modelo VARCHAR2(4),
    velocidad FLOAT,
    RAM VARCHAR2(4),
    HD VARCHAR2(3),
    Pantalla VARCHAR2(5),
    Precio INT,
    CONSTRAINT Portatiles_PK PRIMARY KEY (modelo),
    CONSTRAINT Portatiles_Productos_FK FOREIGN KEY (modelo) REFERENCES Productos(modelo)
);

CREATE TABLE Impresoras(
    modelo VARCHAR2(4),
    color CHAR(1),
    tipo VARCHAR2(7),
    Precio INT,
    CONSTRAINT Impresoras_PK PRIMARY KEY (modelo),
    CONSTRAINT Impresoras_Productos_FK FOREIGN KEY (modelo) REFERENCES Productos(modelo)
);
