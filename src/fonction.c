#ifdef HAVE_CONFIG_H
#   include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonction.h"

enum
{
	ETEMPS,
	EJOUR,
	EENTREE,
	EPLAT,
	EDESSERT,
	EDECHETS,
	COLUMNS
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int verif(Menus m,char nom_fichier[])
{
	FILE *f=NULL;
        char cht[20],chj[20],che[20],chp[20],chd[20];
        int d,trouve=1;

	f=fopen(nom_fichier,"r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d",cht,chj,che,chp,chd,&d)!=EOF)
		{
			if ((strcmp(m.temps,cht)==0) && (strcmp(m.jour,chj)) && (strcmp(m.menu.entree,che)==0) && (strcmp(m.menu.plat_principale,chp)==0) && (strcmp(m.menu.dessert,chd)==0) && (m.dechets==d))
			{
			trouve=0;
			}
		}
	}
	fclose(f);
	return (trouve);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int rechercher_menu(char nom_fichier[],char jour[],char temps[])
{
	FILE *f=NULL;
        Menus m;
        char cht[20],chj[20],che[20],chp[20],chd[20];
        int d,trouve=0;
        
	f=fopen(nom_fichier,"r");
        if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d\n",cht,chj,che,chp,chd,&d)!=EOF)
		{
			if ((strcmp(chj,jour)==0) && (strcmp(cht,temps)==0))
			{
			trouve=1;
			}
		}
	}
	fclose(f);
	return (trouve);       
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ajout_menu(Menus m,char nom_fichier[])
{
	FILE *f;
	f=fopen(nom_fichier,"a");
	if(f != NULL)
	{
		fprintf(f,"%s %s %s %s %s %d\n", m.temps, m.jour, m.menu.entree, m.menu.plat_principale, m.menu.dessert, m.dechets);
		fclose(f);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modifier_menu(char nom_fichier[],Menus m)
{
        
	supprimer_menu(menu.txt,m.jour,m.temps);
	ajout_menu(m,menu.txt);
        return m;
}
/*        

FILE *f=NULL;
        FILE *mo=NULL;
        char cht[20],chj[20],che[20],chp[20],chd[20];
        int d;

        f=fopen(nom_fichier,"r");
        mo=fopen("mod.txt","a");


if(f!=NULL)
        {
            while(fscanf(f,"%s %s %s %s %s %d",cht,chj,che,chp,chd,&d)!=EOF)
            {
                if ((strcmp(cht,m.temps)!=0)||(strcmp(chj,m.jour)!=0))
                {
                    fprintf(mo,"%s %s %s %s %s %d\n",cht,chj,che,chp,chd,d);
                }
		else
                {
		fprintf(mo,"%s %s %s %s %s %d\n",m.temps,m.jour,m.menu.entree,m.menu.plat_principale,m.menu.dessert,m.dechets);
                }
            }
        }
        fclose(f);
        fclose(mo);
        remove("menu.txt");
        rename("mod.txt","menu.txt");*/
    

/********************************************************************************/

void supprimer_menu(char nom_fichier[],char jour[],char temps[])
{
        FILE *f=NULL;
        FILE *s=NULL;
        char cht[20],chj[20],che[20],chp[20],chd[20];
        int d;
	

	f=fopen(nom_fichier,"r");
	s=fopen("sup.txt","a");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d",cht,chj,che,chp,chd,&d)!=EOF)
		{
			if ((strcmp(cht,temps)!=0)||(strcmp(chj,jour)!=0))
			{
			fprintf(s,"%s %s %s %s %s %d\n",cht,chj,che,chp,chd,d);
			}
		}
	}
	fclose(f);
	fclose(s);
	remove(nom_fichier);
	rename("sup.txt","menu.txt");
}

/********************************************************************************/

void afficher_menu(GtkWidget *liste,char texte[])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char cht[20],chj[20],che[20],chp[20],chd[20];
	int d;

	store=NULL;
	FILE *f;

	store = gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("________TEMPS________", renderer, "text",ETEMPS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("________JOUR________", renderer, "text",EJOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("________ENTREE________", renderer, "text",EENTREE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("________PLAT________", renderer, "text",EPLAT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("________DESSERT________", renderer, "text",EDESSERT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("________DECHETS________", renderer, "text",EDECHETS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);

	f=fopen(texte,"r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("menu.txt", "r");
		while(fscanf(f," %s %s %s %s %s %d ",cht,chj,che,chp,chd,&d)!=EOF)
		{
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store,&iter,ETEMPS,cht,EJOUR,chj,EENTREE,che,EPLAT,chp,EDESSERT,chd,EDECHETS,d,-1);
		}
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}

/********************************************************************************/

Menus meilleur_menu(char nom_fichier[])
{
	FILE *f=NULL;
	Menus m;
	char cht[20],chj[20],che[20],chp[20],chd[20],entree[20],plat[20],dessert[20];
	int d,cmp=100000;


	f=fopen(nom_fichier,"r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d",cht,chj,che,chp,chd,&d)!=EOF)
		{
			if(cmp>d)
			{
			cmp=d;
			strcpy(m.temps,cht);
			strcpy(m.jour,chj);
			strcpy(m.menu.entree,che);
			strcpy(m.menu.plat_principale,chp);
			strcpy(m.menu.dessert,chd);
			m.dechets=d;
			}
		}
	fclose(f);
	}
	return m;
}

/********************************************************************************/

