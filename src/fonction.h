#include <gtk/gtk.h>


typedef struct
{
	char entree[50];
	char plat_principale[50];
	char dessert[50];
}plat;

typedef struct
{
	char temps[20];
	char jour[20];
	plat menu;
	int dechets;
}Menus;

/********************************************************************************/

int verif(Menus m,char nom_fichier[]);

int rechercher_menu(char nom_fichier[],char jour[],char temps[]);

void ajout_menu(Menus m,char nom_fichier[]);

void modifier_menu(char nom_fichier[],Menus m);

void supprimer_menu(char nom_fichier[],char jour[],char temps[]);

Menus meilleur_menu(char nom_fichier[]);

void afficher_menu(GtkWidget *liste,char texte[]);

/********************************************************************************/

