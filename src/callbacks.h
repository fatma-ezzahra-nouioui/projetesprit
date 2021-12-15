#include <gtk/gtk.h>


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rafraichir_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_meilleur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_diner_rechercher_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home5_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_dejeuner_rechercher_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_chercher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_diner_ajouter_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home1_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_enregister_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_dejeuner_ajouter_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_diner3_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home3_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_dejeuner3_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_suppression_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_connection_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_diner_modification_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_dejeuner_modification_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home2_clicked                (GtkButton       *button,
                                        gpointer         user_data);
