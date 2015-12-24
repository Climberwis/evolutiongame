#include<stdio.h>
#include<gtk/gtk.h>
#include"life.h"

int main(int argc, char *argv[]){
	GtkWidget *window;
	GtkWidget *map, *menu, *menu_polozenie;
	GtkWidget *spiece_choose, *spiece_name, *plant, *herbivore, *carnivore;
	GtkWidget *size, *map_size, *start_button, *stop_button;
	/*initializing window*/
	gtk_init (&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_resize(GTK_WINDOW(window), 800, 640);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title (GTK_WINDOW(window), "Small Game of Evolution");
	/*Generating map*/
		

	/*Creating Menu*/
		menu_polozenie = gtk_alignment_new( 1, 0.25, 0.1, 0.1 );
		menu = gtk_vbox_new(FALSE, 1);
		spiece_name = gtk_label_new("Choose the spieces:");
		gtk_container_add(GTK_CONTAINER(menu), spiece_name);
		spiece_choose = gtk_combo_box_new_text();
		gtk_combo_box_append_text(GTK_COMBO_BOX(spiece_choose), "PLANT");
		gtk_combo_box_append_text(GTK_COMBO_BOX(spiece_choose), "HERBIVORE");
		gtk_combo_box_append_text(GTK_COMBO_BOX(spiece_choose), "CARNIVORE");
		gtk_container_add(GTK_CONTAINER(menu), spiece_choose);
		map_size = gtk_label_new("Map size:");
		gtk_container_add(GTK_CONTAINER(menu), map_size);
		size = gtk_combo_box_new_text();
		gtk_combo_box_append_text(GTK_COMBO_BOX(size), "100x100");
		gtk_combo_box_append_text(GTK_COMBO_BOX(size), "200x200");
		gtk_combo_box_append_text(GTK_COMBO_BOX(size), "300x300");
		gtk_container_add(GTK_CONTAINER(menu), size);
		start_button = gtk_button_new_with_label("START");
		stop_button = gtk_button_new_with_label("STOP");
		gtk_box_pack_start (GTK_BOX(menu), start_button, TRUE, TRUE, 0);
		gtk_box_pack_start (GTK_BOX(menu), stop_button, TRUE, TRUE, 0);
		gtk_container_add(GTK_CONTAINER(window), menu_polozenie);
		gtk_container_add(GTK_CONTAINER(menu_polozenie), menu);
	


	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all (window);
	gtk_main ();
return 0;
}
