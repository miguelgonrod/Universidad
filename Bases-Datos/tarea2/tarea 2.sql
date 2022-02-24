USE tecnologia_db;
SELECT `Modelo` FROM  `tecnologia_db`.`Productos`;

SELECT DISTINCT `Fabricante` FROM `tecnologia_db`.`Productos`;
SELECT * FROM `tecnologia_db`.`Productos` WHERE `tipo`='pc' or `tipo`='laptop';
SELECT * FROM `tecnologia_db`.`PC` WHERE `RAM`=256;
SELECT * FROM `tecnologia_db`.`PC` WHERE `Precio`<1100;
SELECT * FROM `tecnologia_db`.`Portatiles` WHERE `Precio` < 1400 AND `HD` >= 50;
SELECT * FROM `tecnologia_db`.`Impresoras` WHERE `Tipo` = 'laser';
SELECT * FROM `Portatiles` AS `por`,`Productos` AS `pro` WHERE `por`.`RAM`>=256 AND `pro`.`modelo`=`por`.`modelo` AND `pro`.`Fabricante`='D';
