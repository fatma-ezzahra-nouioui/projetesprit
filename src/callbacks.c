#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"



int t,CA,CM,CR;


void
on_button_connection_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *login;
	GtkWidget *id;
	GtkWidget *Gestion;
	GtkWidget *authentification;
	char log[20];
	char ident[20];

	login = lookup_widget (button, "entry_login");
	strcpy(log, gtk_entry_get_text(GTK_ENTRY(login)));

	id = lookup_widget (button, "entry_id");
	strcpy(ident, gtk_entry_get_text(GTK_ENTRY(id)));

	if((strcmp(log,"fatma")==0) && (strcmp(ident,"nouioui")==0))
	{
		authentification = lookup_widget(button,"authentification");
		Gestion = create_Gestion();
		gtk_widget_show (Gestion);
		gtk_widget_hide(authentification);
	}
}

void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestion;
	GtkWidget *Ajout;

	Gestion = lookup_widget(button,"Gestion");
	Ajout = create_Ajout ();
	gtk_widget_show (Ajout);
	gtk_widget_hide(Gestion);
}

void
on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{  
	GtkWidget *Gestion;
	GtkWidget *Rechercher;

	Gestion = lookup_widget(button,"Gestion");
	Rechercher = create_Rechercher ();
	gtk_widget_show (Rechercher);
	gtk_widget_hide(Gestion);
             
}

void
on_button_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestion;
	GtkWidget *Supprimer;

	Gestion = lookup_widget(button,"Gestion");
	Supprimer = create_Supprimer ();
	gtk_widget_show (Supprimer);
	gtk_widget_hide(Gestion);
}

void
on_button_meilleur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *output;
        char winner[200],che[20],chp[20],chd[20],msg[200];
	Menus m;

	m=meilleur_menu("menu.txt");
	strcpy(che,m.menu.entree);
	strcpy(chp,m.menu.plat_principale);
	strcpy(chd,m.menu.dessert);

	strcat(che,"/");
	strcpy(winner,che);
	strcat(chp,"/");
	strcat(winner,chp);
	strcat(winner,chd);
	
	output = lookup_widget(button,"label_affichage_meilleur_menu"); 
	
	strcpy(msg,"Le meilleur menu est = ");
	strcat(msg,winner);
	gtk_label_set_text(GTK_LABEL(output),msg);
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar* temps;
	gchar* jour;
	gchar* entree;
	gchar* plat;
	gchar* dessert ;
	gchar* dechets;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &temps, 1, &jour, 2, &entree, 3, &plat, 4, &dessert, 5,&dechets, -1);
		afficher_menu(treeview,"menu.txt");
	}
}

void
on_button_home1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestion;
	GtkWidget *Ajout;

	Ajout = lookup_widget(button,"Ajout");
	Gestion = create_Gestion();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Ajout);
}

void
on_checkbutton_dejeuner_ajouter_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CA = 1;
}

void
on_checkbutton_diner_ajouter_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CA = 2;
}

void
on_button_enregister_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *Ajout;
	GtkWidget *Gestion;
	GtkWidget *temps;
	GtkWidget *jour;
	GtkWidget *entree;
	GtkWidget *plat_principal;
	GtkWidget *dessert;
	GtkWidget *dechets;
	GtkWidget *combobox_jour_ajouter;
	char che[20],chp[20],chd[20];

	int x;
	Menus m;

	if(CA==1)
	strcpy(m.temps,"dejeuner");

	if(CA==2)
	strcpy(m.temps,"diner");

	combobox_jour_ajouter = lookup_widget(button,"combobox_jour_ajouter");

	if(strcmp("lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_ajouter)))==0)
	strcpy(m.jour,"lundi");

	if(strcmp("mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_ajouter)))==0)
	strcpy(m.jour, "mardi");

	if(strcmp("mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_ajouter)))==0)
	strcpy(m.jour, "mercredi");

	if(strcmp("jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_ajouter)))==0)
	strcpy(m.jour, "jeudi");

	if(strcmp("vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_ajouter)))==0)
	strcpy(m.jour, "vendredi");

	if(strcmp("samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_ajouter)))==0)
	strcpy(m.jour, "samedi");

	entree = lookup_widget (button, "entry_entree_ajouter");
	strcpy(m.menu.entree, gtk_entry_get_text(GTK_ENTRY(entree)));

	plat_principal = lookup_widget (button, "entry_plat_principal_ajouter");
	strcpy(m.menu.plat_principale, gtk_entry_get_text(GTK_ENTRY(plat_principal)));

	dessert = lookup_widget (button, "entry_dessert_ajouter");
	strcpy(m.menu.dessert, gtk_entry_get_text(GTK_ENTRY(dessert)));

	dechets = lookup_widget(button, "spinbutton_dechets_ajouter");
	m.dechets = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (dechets));

	x=verif(m,"menu.txt");

	if(x==1)
	{
	ajout_menu(m,"menu.txt");
	Ajout = lookup_widget(button,"Ajout");
	Gestion = create_Gestion();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Ajout);
	}
}

void
on_button_home5_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestion;
	GtkWidget *Rechercher;

	Rechercher = lookup_widget(button,"Rechercher");
	Gestion = create_Gestion ();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Rechercher);
}

void
on_checkbutton_dejeuner_rechercher_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CR = 1;
}


void
on_checkbutton_diner_rechercher_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CR = 2;
}

void
on_button_chercher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Modifier;
	GtkWidget *Rechercher;
	GtkWidget *temps;
	GtkWidget *jour;
	GtkWidget *combobox_jour_rechercher;
	int x;
	Menus m;

	combobox_jour_rechercher = lookup_widget(button,"combobox_jour_rechercher");

	if(strcmp("lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_rechercher)))==0)
	strcpy(m.jour, "lundi");

	if(strcmp("mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_rechercher)))==0)
	strcpy(m.jour, "mardi");

	if(strcmp("mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_rechercher)))==0)
	strcpy(m.jour, "mercredi");

	if(strcmp("jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_rechercher)))==0)
	strcpy(m.jour, "jeudi");

	if(strcmp("vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_rechercher)))==0)
	strcpy(m.jour, "vendredi");

	if(strcmp("samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_rechercher)))==0)
	strcpy(m.jour, "samedi");

	if(CR==1)
	strcpy(m.temps,"dejeuner");

	if(CR==2)
	strcpy(m.temps,"diner");

	x=rechercher_menu("menu.txt",m.jour,m.temps);

	if(x==1)
	{
	Rechercher = lookup_widget(button,"Rechercher");
	Modifier = create_Modifier ();
	gtk_widget_show (Modifier);
	gtk_widget_hide(Rechercher);
	}
}

void
on_button_home2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestion;
	GtkWidget *Modifier;

	Modifier = lookup_widget(button,"Modifier");
	Gestion = create_Gestion ();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Modifier);
}

void
on_checkbutton_dejeuner_modification_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CM = 1;
}


void
on_checkbutton_diner_modification_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CM = 2;
}

void
on_button_sauvegarder_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox_jour_modification;
	GtkWidget *Gestion;
	GtkWidget *Modifier;
	GtkWidget *entree;
	GtkWidget *plat_principal;
	GtkWidget *dessert;
	GtkWidget *dechets;

	char temps[20];
	int x;
	Menus m;

////////////////////////////////////////

	entree = lookup_widget (button, "entry_modification");
	strcpy(m.menu.entree, gtk_entry_get_text(GTK_ENTRY(entree)));

	plat_principal = lookup_widget (button, "entry_plat_modification");
	strcpy(m.menu.plat_principale, gtk_entry_get_text(GTK_ENTRY(plat_principal)));

	dessert = lookup_widget (button, "entry_dessert_modification");
	strcpy(m.menu.dessert, gtk_entry_get_text(GTK_ENTRY(dessert)));

	dechets = lookup_widget(button, "spinbutton_dechets_modification");
	m.dechets = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (dechets));

/////////////////////////////////

	combobox_jour_modification = lookup_widget(button,"combobox_jour_modification");

	if(strcmp("lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_modification)))==0)
	strcpy(m.jour, "lundi");

	if(strcmp("mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_modification)))==0)
	strcpy(m.jour, "mardi");

	if(strcmp("mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_modification)))==0)
	strcpy(m.jour, "mercredi");

	if(strcmp("jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_modification)))==0)
	strcpy(m.jour, "jeudi");

	if(strcmp("vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_modification)))==0)
	strcpy(m.jour, "vendredi");

	if(strcmp("samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_jour_modification)))==0)
	strcpy(m.jour, "samedi");

	if(CM==1)
	strcpy(m.temps,"dejeuner");

	if(CM==2)
	strcpy(m.temps,"diner");

	modifier_menu("menu.txt",m);
//	supprimer_menu("menu.txt",m.jour,m.temps);
//	ajout_menu(m,"menu.txt");

	Modifier = lookup_widget(button,"Modifier");
	Gestion = create_Gestion ();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Modifier);
	
}

void
on_button_home3_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestion;
	GtkWidget *Supprimer;

	Supprimer = lookup_widget(button,"Supprimer");
	Gestion = create_Gestion ();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Supprimer);
}

void
on_radiobutton_dejeuner3_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	t=1;
}


void
on_radiobutton_diner3_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	t=2;
}

void
on_button_suppression_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox_suppression;
	GtkWidget *Gestion;
	GtkWidget *Supprimer;
	char temps[20],jour[20];
	int x;


	combobox_suppression = lookup_widget(button,"combobox_suppression");

	if(strcmp("lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_suppression)))==0)
	strcpy(jour, "lundi");

	if(strcmp("mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_suppression)))==0)
	strcpy(jour, "mardi");

	if(strcmp("mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_suppression)))==0)
	strcpy(jour, "mercredi");

	if(strcmp("jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_suppression)))==0)
	strcpy(jour, "jeudi");

	if(strcmp("vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_suppression)))==0)
	strcpy(jour, "vendredi");

	if(strcmp("samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_suppression)))==0)
	strcpy(jour, "samedi");

	if(t==1)
	strcpy(temps,"dejeuner");

	if(t==2)
	strcpy(temps,"diner");

	x=rechercher_menu("menu.txt",jour,temps);

	if(x==1)
	{
	supprimer_menu("menu.txt",jour,temps);
	t=0;
	Supprimer = lookup_widget(button,"Supprimer");
	Gestion = create_Gestion ();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Supprimer);
	}
}



void
on_button_rafraichir_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview;
	GtkWidget *Gestion;

	Gestion = lookup_widget(button,"Gestion");
	treeview=lookup_widget(button,"treeview");
	Gestion = create_Gestion ();
	gtk_widget_show (Gestion);
	gtk_widget_hide(Gestion);
	afficher_menu(treeview,"menu.txt");
}

