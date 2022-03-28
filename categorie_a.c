#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <time.h>
#include <math.h>

#include "categorie_a.h"

/**
* \author YÉO Niyona Emmanuel
* \version 26.03
* \date 26 Mars 2022
* \brief Ce fichier permet la gestion des véhicules de catégorie A 
*       (insertion, affichage, modification, sortie)
*/

/** Appel du fichier categorie_a.c
* \file categorie_a.c
* \fn void insertion_cat_a ()
* \fn void affiche_cat_a ()
* \fn void sortie_cat_a ()
*/

static char HOST[255] = "localhost";
static char USER[255] = "bruno";
static char PASSWORD[255] = "Poisson2020@";
static char DBNAME[255] = "parking";

static unsigned int port = 3306;


MYSQL *connexion;
MYSQL_RES *res;
MYSQL_ROW row;


void insertion_cat_a() {

  int h, min, s, day, mois, an;
  time_t now;
    
  time(&now);
  struct tm *local = localtime(&now);
  h = local->tm_hour;        
  min = local->tm_min;            
  day = local->tm_mday;          
  mois = local->tm_mon + 1;     
  an = local->tm_year + 1900;  
  printf("L'heure d'ENTREE: %02d:%02d\n", h, min);
  /**Afficher la date courante*/
  printf("La date d'ENTREE: %02d/%02d/%d\n", day, mois, an);

    char matricule[25];
    char marque[25];
    char couleur[25];
    char query[255];
    char autre[255];
    
    printf("Veuillez saisir le matricule du véhicule de categorie A:\n");
    scanf("%s", matricule);
    printf("Veuillez saisir la marque du véhicule de categorie A :\n");
    scanf("%s", marque);
    printf("Veuillez saisir la couleur du véhicule de categorie A :\n");
    scanf("%s", couleur);
    connexion = mysql_init(NULL);
    
    if (! (mysql_real_connect(connexion, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0))) {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(connexion), mysql_errno(connexion));
        exit(1);
    }
    sprintf(query, "INSERT INTO categorie_a (matricule, marque, couleur, date_entre, date_sortie, temps_passe_parking) VALUES('%s' , '%s' , '%s' , '%ld', '%d', '%d');", matricule, marque, couleur, time(&now),0, 0);

    if (mysql_query(connexion, query)) {
        printf(":-(");
    }

    sprintf(autre, "SELECT * FROM nbr_engins;");
     if (mysql_query(connexion, autre)) {
        printf(":-(");
    }
    res = mysql_store_result(connexion);

    while (row = mysql_fetch_row(res)) {

        if(atoi(row[1]) > 0) {

            sprintf(autre, "UPDATE nbr_engins SET nbr_moto = nbr_moto - 1");
            if (mysql_query(connexion, autre))
            {
                printf(":-(");
            }
        }
        else {
            printf("IL N'Y A PLUS DE PLACE DANS LE PARKING POUR DES VEHICULES DE CATEGORIE A.\n");
        }
    }
    exit(EXIT_SUCCESS);
    
}

/**AFFICHER LES VEHICULES DE CATEGORIE A*/
void affiche_cat_a(){

    connexion = mysql_init(NULL);
    
    if (! (mysql_real_connect(connexion, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0))) {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(connexion), mysql_errno(connexion));
        exit(1);
    }

     char aut[200]=" ";
     //printf("ok");
     sprintf(aut, "SELECT * FROM categorie_a");
     if (mysql_query(connexion, aut)) {
        printf(":-(");
    }
        res = mysql_store_result(connexion);
    while (row = mysql_fetch_row(res)) {
        printf("matricule \t marque \t couleur \n\n");
        printf("%s\t%s\t%s\n", row[1], row[2], row[3]);
    }
    mysql_free_result(res);
    mysql_close(connexion);
}

/**RECHERCHER UN VEHICULE DE CATEGORIE A*/
void rechercher_cat_a(){

	connexion = mysql_init(NULL);
    
    if (! (mysql_real_connect(connexion, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0))) {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(connexion), mysql_errno(connexion));
        exit(1);
    }

     char aut_r[200]=" ";
     char matri_r[25];
     printf("Veuillez saisir le numero d'IMMATRICULATION : \n");
     printf("   ");
     scanf("%s", matri_r);
    
     sprintf(aut_r, "SELECT * FROM categorie_a WHERE matricule ='%s';", matri_r);
     if (mysql_query(connexion, aut_r))
        {
            printf(":-(");
        }
        res = mysql_store_result(connexion);
    while (row = mysql_fetch_row(res))
    {
         printf("matricule \t marque \t couleur \n\n");
         printf("%s\t%s\t%s\n", row[1], row[2], row[3]);
    }
    mysql_free_result(res);
    mysql_close(connexion);
}

/**SORTIE DE VEHICULE DE CATEGORIE A*/
void sortie_cat_a() {
	connexion = mysql_init(NULL);
    
    if (! (mysql_real_connect(connexion, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(connexion), mysql_errno(connexion));
        exit(1);
    }
    
    char matri[25];
    char autre[255];
    double total_tmp;
    int som_pay;
    float nbr_min;
    float nbr_h;
    int dif;

    int h, min, s, day, mois, an;
    time_t now;
        
    /**Renvoie l'heure actuelle*/
    time(&now);
    /**Convertir au format heure locale*/
    struct tm *local = localtime(&now);
    h = local->tm_hour;        
    min = local->tm_min;       
    s = local->tm_sec;       
    day = local->tm_mday;          
    mois = local->tm_mon + 1;     
    an = local->tm_year + 1900;  
    printf("L'heure de SORTIE: %02d:%02d:%02d\n", h, min, s);
    /**Afficher la date courante*/
    printf("La date de SORTIE: %02d/%02d/%d\n", day, mois, an);

    
    printf("==> Veuillez saisir le numero d'IMMATRICULATION de votre Engin : \n");
    printf("====> ");
    scanf("%s", matri);

    sprintf(autre, "SELECT * FROM categorie_a WHERE matricule ='%s';", matri);
     if (mysql_query(connexion, autre))
    {
        printf(":-(");
    }
    res = mysql_store_result(connexion);

    while (row = mysql_fetch_row(res))
    {
        printf("Categorie A D'IMMATRICULATION %s", row[1]);
        printf(" DEMANDE A SORTIR \n");
        printf("\n");
    
    

    sprintf(autre, "UPDATE categorie_a SET date_sortie = '%ld' WHERE matricule = '%s';", time(&now),matri);
    if (mysql_query(connexion, autre))
        {
            printf(":-( ECHEC UPDATE\n");
        }

    dif = (time(&now)-atoi(row[4]));

    sprintf(autre, "UPDATE categorie_a SET temps_passe_parking = '%d' WHERE matricule = '%s';",dif , matri);
        if (mysql_query(connexion, autre))
        {
            printf(":-( ECHEC UPDATE\n");
        }
    
        if (dif <= 86399)
    {
        total_tmp = dif;
        som_pay = ceil((total_tmp/3600))*500;
        nbr_min = (total_tmp/60);
        nbr_h = floor(nbr_min/60);
        printf("Votre *véhicule* a passé: %f ", nbr_h);
        printf("heures dans notre Parking \n");
        printf("Votre *véhicule* a passé: %f ", nbr_min);
        printf("Minutes dans notre Parking \n");
        printf("Vous devriez payer : %d ", som_pay);
        printf(" FCFA \n");
        printf("\n");
        printf("AUREVOIR ET MERCI DE NOUS AVOIR FAIT CONFIANCE \n");
    }
    if (dif >= 86400)
    {
        total_tmp = dif;
        som_pay = ceil((total_tmp/3600))*20000;
        nbr_min = (total_tmp/60);
        nbr_h = floor(nbr_min/60);
        printf("Votre *véhicule* a passé: %f ", nbr_h);
        printf("heures dans notre Parking \n");
        printf("Votre *véhicule* a passé: %f ", nbr_min);
        printf("Minutes dans notre Parking \n");
        printf("Vous devriez payer : %d ", som_pay);
        printf(" FCFA \n");
        printf("\n");
        printf("AUREVOIR ET MERCI DE NOUS AVOIR FAIT CONFIANCE \n");
    }
}


    sprintf(autre, "UPDATE nbr_engins SET nbr_moto = nbr_moto+ 1");
    if (mysql_query(connexion, autre))
    {
        printf(":-(");
    }
    
    sprintf(autre, "DELETE FROM categorie_a WHERE matricule = '%s';", matri);
    if (mysql_query(connexion, autre))
    {
    printf(":-(");
    }

    exit(EXIT_SUCCESS);
    

}
