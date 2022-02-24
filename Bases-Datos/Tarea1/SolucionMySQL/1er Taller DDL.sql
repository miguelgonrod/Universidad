CREATE SCHEMA IF NOT EXISTS `tecnologia_db`;
USE `tecnologia_db` ;

CREATE TABLE IF NOT EXISTS `tecnologia_db`.`Productos` (
  `Fabricante` VARCHAR(3) NOT NULL,
  `Modelo` INT(4) NOT NULL,
  `Tipo` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Modelo`)
);

CREATE TABLE IF NOT EXISTS `tecnologia_db`.`PC` (
  `Modelo` INT(4) NOT NULL,
  `Velocidad` DOUBLE NOT NULL,
  `RAM` INT(5) NOT NULL,
  `HD` INT(5) NOT NULL,
  `CD` VARCHAR(4) NOT NULL,
  `Precio` INT(6) NOT NULL,
  PRIMARY KEY (`Modelo`),
  CONSTRAINT `fk_PC_Modelo`
    FOREIGN KEY (`Modelo`)
    REFERENCES `tecnologia_db`.`Productos` (`Modelo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);

CREATE TABLE IF NOT EXISTS `tecnologia_db`.`Portatiles` (
  `modelo` INT(4) NOT NULL,
  `velocidad` DOUBLE NOT NULL,
  `RAM` INT(5) NOT NULL,
  `HD` INT(5) NOT NULL,
  `Pantalla` DOUBLE NOT NULL,
  `Precio` INT(6) NOT NULL,
  PRIMARY KEY (`modelo`),
  CONSTRAINT `fk_Portátiles_modelo`
    FOREIGN KEY (`modelo`)
    REFERENCES `tecnologia_db`.`Productos` (`Modelo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);

CREATE TABLE IF NOT EXISTS `tecnologia_db`.`Impresoras` (
  `modelo` INT(4) NOT NULL,
  `color` ENUM('FALSO', 'VERDADERO') NOT NULL,
  `tipo` ENUM('ink-jet', 'laser', 'dry') NOT NULL,
  `precio` INT(6) NOT NULL,
  PRIMARY KEY (`modelo`),
  CONSTRAINT `fk_Impresoras_modelo`
    FOREIGN KEY (`modelo`)
    REFERENCES `tecnologia_db`.`Productos` (`Modelo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);
