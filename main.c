#include<stdio.h>
#include<gtk/gtk.h>
#include"life.h"

void resize(GtkWidget *a, gpointer b){
}

int main(int argc, char *argv[]){
	Maps *map;
	map = g_malloc ( sizeof( Maps ) );
	map->n_xy = 100;

	gtk_init (&argc, &argv);

	map->window = g_object_new( GTK_TYPE_WINDOW, "window-position", GTK_WIN_POS_CENTER,
	"default-width", 800, "default-height", 640, "title", "Small Game of Evolution", "border-width", 5, NULL );
	/*Generating map*/
	create_map(map);

	/*Creating Menu*/
		map->menu = gtk_fixed_new(); 
		gtk_container_add(GTK_CONTAINER(map->window), map->menu);

		/*SPIECES CHOOSE PART*/
		map->labels = gtk_label_new("SPIECES"); 
		gtk_fixed_put(GTK_FIXED(map->menu), map->labels, 610, 50);
		map->spiece_choose = gtk_combo_box_new_text(); 
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "PLANT");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "HERBIVORE");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "CARNIVORE");
		gtk_widget_set_size_request(map->spiece_choose, 100, 50);
		gtk_fixed_put(GTK_FIXED(map->menu), map->spiece_choose, 600, 70);

		/*MAP SIZE CHOOSE PART*/
		map->labels = gtk_label_new("MAP SIZE"); 
		gtk_fixed_put(GTK_FIXED(map->menu), map->labels, 610, 150);
		map->size = gtk_combo_box_new_text(); 
		gtk_widget_set_size_request(map->size, 100, 50);
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->size), "100x100");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->size), "200x200");
		gtk_fixed_put(GTK_FIXED(map->menu), map->size, 600, 170);
			g_signal_connect(G_OBJECT(map->size), "changed", G_CALLBACK(resize), (gpointer)map);
		
		/*START/PAUSE BUTTON PART*/
		map->start_button = gtk_toggle_button_new_with_label("START"); 
		gtk_widget_set_size_request(map->start_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->menu), map->start_button, 600, 300);
		
		/*STOP BUTTON PART*/
		map->stop_button = gtk_button_new_with_label("STOP"); 
		gtk_widget_set_size_request(map->stop_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->menu), map->stop_button, 600, 370);
			

	
	g_signal_connect(G_OBJECT(map->window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all (map->window);
	gtk_main ();
return 0;
}
