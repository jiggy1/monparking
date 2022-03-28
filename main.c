#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <time.h>
#include <math.h>

// mes modules
#include "categorie_a.h"  // motos
#include "categorie_b.h"  // vehicules personnels
#include "categorie_c.h"  // poids lourds

// les constantes
# define ERRMSG1 "ERREUR :-(, VEUILLEZ SAISIR LE CHIFFRE 1 OU 2 OU 3 \n"
# define ERRMSG2 "ERREUR :-(, VEUILLEZ SAISIR LE CHIFFRE 1 OU 2 \n"

static char HOST[255] = "localhost";
static char USER[255] = "bruno";
static char PASSWORD[255] = "Poisson2022@";
static char DBNAME[255] = "parking";

static unsigned int port = 3306;


MYSQL *connexion;
MYSQL_RES *res;
MYSQL_ROW row;

void nombre_engin(){
    mysql_query(connexion, "SELECT nbr_moto, nbre_cat_b, nbre_cat_c FROM nbr_engins");
    res = mysql_store_result(connexion);

    while (row = mysql_fetch_row(res)) {
        printf("Nombre de places par catégorie: \n");
        printf("Categorie A: %s \n", row[0]);
        printf("Categorie B: %s \n", row[1]);
        printf("Categorie C: %s \n", row[2]);
    }
    printf("\n");
    mysql_free_result(res);
    mysql_close(connexion);
}


int main() {
     

    connexion = mysql_init(NULL);
    
    if (! (mysql_real_connect(connexion, HOST, USER, PASSWORD, DBNAME, 0, NULL, 0)))
    {
        //fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(connexion), mysql_errno(connexion));
        exit(1);
    }
    

    int choix1;
    int choix2;
    int choix3;
    int choix4;

    do {
        nombre_engin();

        printf("********************************************** \n");
        printf("1- Enregistrer un categorie_b entrant \n"); 
        printf("2- Enregistrer la sortie d'un categorie_b \n");
        printf("3- Affichage le nombre de places du parking \n");
        printf("4- Recherche un categorie_b dans le parking \n");
        printf("5- Afficher les vehicules du parking \n");

        printf("Entrez votre choix (1 ou 2 ou 3 ou 4 ou 5): ");
        scanf("%i", &choix1);

        switch(choix1) {
        case 1:
            do {
                printf("Enregistrement de categorie_b entrant \n"); 
               printf("1- Categorie A \n");
               printf("2- Categorie B \n");
               printf("3- Categorie C \n");
               printf("Entrez la categorie (saisissez 1 ou 2 ou 3) : \n");
               scanf("%i", &choix2);

               switch (choix2){
                    case 1:
                            printf("Categorie A\n");
                            insertion_cat_a();
                            //affiche();
                        break;

                        case 2:
                            printf("Categorie B \n");
                            insertion_cat_b();
                        break;

                        case 3:
                            printf("Categorie C \n");
                            insertion_cat_c();
                            break;
                    
                    default:
                            system("cls");
                            printf(ERRMSG1);
                        break;
               }

            } while (choix2 != 3);
            getchar();
     
        break;

        case 2:
            do {
               printf("LES ENGINS SORTANTS \n");
               printf("1- Categorie A \n");
               printf("2- Categorie B \n");
               printf("3- Categorie C \n");
               printf("Entrez la categorie (saisissez 1 ou 2 ou 3) : \n");
               scanf("%i", &choix3);

               switch (choix3)
               {
               case 1:
                    printf("BONNE ROUTE ENGIN A ROUES\n");
                    sortie_cat_a();
                    
                    //affiche();
                break;

                case 2:
                    printf("BONNE ROUTE ENGIN VEHICULE \n");
                    sortie_cat_b();
                    //update_sortie_engin_deux_roues();
                    //affiche_vehicule();
                break;

                case 3:
                    printf("BONNE ROUTE ENGIN CAMION \n");
                    sortie_cat_c();
                    //affiche_camion();
                break;
               
               default:
                    system("cls");
                    printf(ERRMSG1);
                break;
               }

            } while (choix2 != 3);
            getchar();   
        break; 

        case 3:
            //system("cls");
            printf("==>NOMBRE DE PLACE DANS PARKING \n");
            nombre_engin();
        break;
        
        case 4:
            printf("==>RECHERHER UN ENGIN DANS LE PARKING \n");

            printf("1- Categorie A \n");
               printf("2- Categorie B \n");
               printf("3- Categorie C \n");
               printf("Entrez la categorie (saisissez 1 ou 2 ou 3) : \n");
               scanf("%i", &choix4);

               switch (choix4)
               {
               case 1:
                    printf("Categorie A\n");
                    rechercher_cat_a();
                break;

                case 2:
                    printf("Categorie B\n");
                    rechercher_cat_b();
                break;

                case 3:
                    printf("Categorie C \n");
                    rechercher_cat_c();
                break;
               
               default:
                    system("cls");
                    printf(ERRMSG1);
                break;
               }
        break;

        case 5:
            printf("==>AFFICHAGE DES ENGINS DANS LE PARKING \n");

            do
            {
               printf("====>1 AFFICHE LES ENGINS A 2 ROUES \n");
               printf("====>2 AFFICHE LES VEHICULE \n");
               printf("====>3 AFFICHE LES CAMIONS \n");
               printf("====>CHOISISSEZ UN ENGIN : \n");
               scanf("%i", &choix4);

               switch (choix4)
               {
                case 1:
                        printf("AFFICHAGE DE ENGIN DE ROUES\n");
                        affiche_cat_a();
                    break;

                    case 2:
                        printf("AFFICHAGE DE VEHICULE \n");
                        affiche_cat_c();
                    break;

                    case 3:
                        printf("AFFICHAGE DE CAMION \n");
                        affiche_cat_c();
                    break;
                
                default:
                        system("cls");
                        printf("ERREUR :-(, VEUILLEZ SAISIR UN CHIFFRE DE 1 À 3 \n");
                    break;
               }
               

            } while (choix4 != 3);
            getchar();
            
        break;
        
        default :
            system("cls");
            printf("ERREUR :-(, VEUILLEZ SAISIR UN CHIFFRE DE 1 À 2 \n");
        break;
        }
        
    } while(choix1 != 4);
    getchar(); /**LA FONCTION getchar PERMET DE RENVOYER VALEUR SAISIR*/

    return 0;


}