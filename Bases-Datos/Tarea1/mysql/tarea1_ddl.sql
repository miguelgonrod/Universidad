CREATE SCHEMA IF NOT EXISTS `tarea1_db`;
USE `tarea1_db`;

CREATE TABLE IF NOT EXISTS `tarea1_db`.`Productos`(
	`Fabricante` VARCHAR(3) NOT NULL,
    `Modelo` INT(4) NOT NULL,
    `Tipo` VARCHAR(45) NOT NULL,
    PRIMARY KEY (`Modelo`)
);

CREATE TABLE IF NOT EXISTS `tarea1_db`.`PC`(
    `Modelo` INT(4) NOT NULL,
    `Velocidad` FLOAT NOT NULL,
    `RAM` VARCHAR(4) NOT NULL,
    `HD` VARCHAR(3) NOT NULL,
    `CD` VARCHAR(3) NOT NULL,
    `Precio` INT(6) NOT NULL,
    PRIMARY KEY (`Modelo`),
    CONSTRAINT `fk_PC_modelo` FOREIGN KEY (`Modelo`) REFERENCES `tarea1_db`.`Productos`(`Modelo`)
);

CREATE TABLE IF NOT EXISTS `tarea1_db`.`Portatiles`(
    `Modelo` INT(4) NOT NULL,
    `Velocidad` FLOAT NOT NULL,
    `RAM` VARCHAR(4) NOT NULL,
    `HD` VARCHAR(3) NOT NULL,
    `Pantallas` VARCHAR(3) NOT NULL,
    `Precio` INT(6) NOT NULL,
    PRIMARY KEY (`Modelo`),
    CONSTRAINT `fk_Portatiles_modelo` FOREIGN KEY (`Modelo`) REFERENCES `tarea1_db`.`Productos`(`Modelo`)
);

CREATE TABLE IF NOT EXISTS `tarea1_db`.`Impresoras`(
    `Modelo` INT(4) NOT NULL,
    `Color` ENUM('FALSO','VERDADERO') NOT NULL,
    `tipo` ENUM('ink-jet','laser','dry') NOT NULL,
    PRIMARY KEY (`Modelo`),
    CONSTRAINT `fk_Impresoras_modelo` FOREIGN KEY (`Modelo`) REFERENCES `tarea1_db`.`Productos`(`Modelo`)
);