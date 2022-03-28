#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <time.h>
#include <math.h>

#include "categorie_c.h"

/**
* \author YEO Niyona Emmanuel
* \version 26.03
* \date 26 Mars 2022
* \brief Ce fichier permet la gestion des vehicules de categorie C(insertion, affichage, modification, sortie)
*/

/** Appel du fichier categorie_c.c
* \file categorie_c.c
* \fn void insertion_cat_c ()
* \fn void affiche_cat_c ()
* \fn void sortie_cat_c ()
*/

static char HOST[255] = "localhost";
static char USER[255] = "bruno";
static char PASSWORD[255] = "Poisson2020@";
static char DBNAME[255] = "parking";

static unsigned int port = 3306;


MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

/**INSERTION ENGIN CAMION*/
void insertion_cat_c(){

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

    char matricule1[25];
    char marque[25];
    char couleur[25];
    char query[255];
    char autre[255];
    
    printf("Veuillez saisir le matricule de votre ENGIN A DEUX ROUES :\n");
    scanf("%s", matricule1);
    printf("Veuillez saisir la marque de votre ENGIN A DEUX ROUES :\n");
    scanf("%s", marque);
    printf("Veuillez saisir la couleur de votre ENGIN A DEUX ROUES :\n");
    scanf("%s", couleur);
    conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    printf("dwqdqw");
    sprintf(query, "INSERT INTO categorie_c (matricule, marque, couleur, date_entre, date_sortie, temps_passe_parking) VALUES('%s' );", matricule1);
    /*
    if (mysql_query(conn, query))
    {
        printf(":-(");
    }


    sprintf(autre, "SELECT * FROM nbr_engin;");
     if (mysql_query(conn, autre))
        {
            printf(":-(");
        }
        res = mysql_store_result(conn);

    while (row = mysql_fetch_row(res))
    {

    if (atoi(row[3]) > 0)
        {

        sprintf(autre, "UPDATE nbr_engin SET nbr_camion = nbr_camion - 1");
        if (mysql_query(conn, autre))
        {
            printf(":-(");
        }
    }
    else{
        printf("===> DESOLER, IL N' Y A PLUS DE PLACE DANS LE PARKING POUR DES CAMIONS. BYE!!! \n");
    }
    exit(EXIT_SUCCESS);
    }
    	 mysql_close(conn);*/
}


/**AFFICHE LES CAMIONS*/
void affiche_cat_c(){

	conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }

     char aut[200]=" ";
     //printf("ok");
     sprintf(aut, "SELECT * FROM categorie_c");
     if (mysql_query(conn, aut))
        {
            printf(":-(");
        }
        res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res))
    {
         printf("matricule \t marque \t couleur \n\n");
         printf("%s\t%s\t%s\n", row[1], row[2], row[3]);
    }
    mysql_free_result(res);
    mysql_close(conn);
}

/**RECHERCHER UN CAMIONS*/
void rechercher_cat_c(){

	conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }

     char aut_r[200]=" ";
     char matri_r[25];
     printf("==> Veuillez saisir le numero d'IMMATRICULATION de votre Engin : \n");
     printf("====> ");
     scanf("%s", matri_r);
    
     sprintf(aut_r, "SELECT * FROM categorie_c WHERE matricule ='%s';", matri_r);
     if (mysql_query(conn, aut_r))
        {
            printf(":-(");
        }
        res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res))
    {
    	 printf("matricule \t marque \t couleur \n\n");
         printf("%s\t%s\t%s\n", row[1], row[2], row[3]);
    }
    mysql_free_result(res);
    mysql_close(conn);
}

/**SORTIE DE CAMION*/
void sortie_cat_c(){
	conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
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
    
    /**Renvoi l'heure actuelle*/
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
    
    sprintf(autre, "SELECT * FROM categorie_c WHERE matricule ='%s';", matri);
     if (mysql_query(conn, autre))
    {
        printf(":-(");
    }
    res = mysql_store_result(conn);
    
    while (row = mysql_fetch_row(res))
    {
        printf("LE CAMION D'IMMATRICULATION %s", row[1]);
        printf(" DEMANDE A SORTIR \n");
        printf("\n");
    
    sprintf(autre, "UPDATE categorie_c SET date_sortie = '%ld' WHERE matricule = '%s';", time(&now),( matri));
    if (mysql_query(conn, autre))
        {
            printf(":-( ECHEC UPDATE\n");
        }

    dif = (time(&now)-atoi(row[4]));

    sprintf(autre, "UPDATE categorie_c SET temps_passe_parking = '%d' WHERE matricule = '%s';", dif,( matri));
        if (mysql_query(conn, autre))
        {
            printf(":-( ECHEC UPDATE\n");
        }

        if (dif <= 86399)
    {
        total_tmp = dif;
        som_pay = ceil((total_tmp/3600))*500;
        nbr_min = (total_tmp/60);
        nbr_h = floor(nbr_min/60);
        printf("Votre Vehicule a passer: %f ", nbr_h);
        printf("heures dans notre Parking \n");
        printf("Votre Camion a passer: %f ", nbr_min);
        printf("Minnutes dans notre Parking \n");
        printf("Vous devriez payer : %d ", som_pay);
        printf(" FCFA \n");
        printf("\n");
        printf("AUREVOIR ET MERCI DE NOUS AVOIR FAIT CONFIANCE !!! \n");
    }
    if (dif >= 86400)
    {
        total_tmp = dif;
        som_pay = ceil((total_tmp/3600))*20000;
        nbr_min = (total_tmp/60);
        nbr_h = floor(nbr_min/60);
        printf("Votre Camion a passer: %f ", nbr_h);
        printf("heures dans notre Parking \n");
        printf("Votre Camion a passer: %f ", nbr_min);
        printf("Minnutes dans notre Parking \n");
        printf("Vous devriez payer : %d ", som_pay);
        printf(" FCFA \n");
        printf("\n");
        printf("AUREVOIR ET MERCI DE NOUS AVOIR FAIT CONFIANCE !!! \n");
    }

}

sprintf(autre, "UPDATE nbr_engin SET nbr_camion = nbr_camion + 1");
    if (mysql_query(conn, autre))
    {
        printf(":-(");
    }
    
    sprintf(autre, "DELETE FROM categorie_c WHERE matricule = '%s';", matri);
    if (mysql_query(conn, autre))
    {
        printf(":-(");
    }

    exit(EXIT_SUCCESS);


}
