DROP TABLE IF EXISTS `categorie_a`;

CREATE TABLE `categorie_a` (
  `id` int NOT NULL AUTO_INCREMENT,
  `matricule` varchar(10) DEFAULT NULL,
  `date_entre` int DEFAULT NULL,
  `date_sortie` int DEFAULT NULL,
  `temps_passe_parking` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


INSERT INTO `categorie_a` VALUES (1,'8448FG01',1618759865,1614903463,1614903463);


DROP TABLE IF EXISTS `categorie_b`;

CREATE TABLE `categorie_b` (
  `id` int NOT NULL AUTO_INCREMENT,
  `matricule` varchar(10) DEFAULT NULL,
  `date_entre` int DEFAULT NULL,
  `date_sortie` int DEFAULT NULL,
  `temps_passe_parking` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


INSERT INTO `categorie_b` VALUES (1,'7575KH01',1618096238,1614903463,1614903463);


DROP TABLE IF EXISTS `categorie_c`;

CREATE TABLE `categorie_c` (
  `id` int NOT NULL AUTO_INCREMENT,
  `matricule` varchar(10) DEFAULT NULL,
  `date_entre` int DEFAULT NULL,
  `date_sortie` int DEFAULT NULL,
  `temps_passe_parking` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


INSERT INTO `categorie_c` VALUES (1,'1802TW01',1618096284,1614903463,1614903463),(2,'8978KI01',1618177062,1614903463,1614903463),(3,'2369JI01',1618179141,1614903463,1614903463);


DROP TABLE IF EXISTS `nbr_engins`;
DROP TABLE IF EXISTS `nbr_engins`;

CREATE TABLE `nbr_engins` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nbr_cat_a` int DEFAULT NULL,
  `nbr_cat_b` int DEFAULT NULL,
  `nbr_cat_c` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

INSERT INTO `nbr_engins` VALUES (1,30,1,14);