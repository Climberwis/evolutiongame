#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void free_mem(Maps *maps){
	/**/
}

int main(int argc, char *argv[]){
	Maps *map;
	map = g_malloc ( sizeof( Maps ) );
	map->n_xy = 100;

	gtk_init (&argc, &argv);

	map->window = g_object_new( GTK_TYPE_WINDOW, "window-position", GTK_WIN_POS_CENTER,
	"default-width", 800, "default-height", 640, "title", "Small Game of Evolution", "border-width", 5, NULL );
	/*Creating Menu*/
		map->game_window = gtk_fixed_new(); 
		gtk_container_add(GTK_CONTAINER(map->window), map->game_window);

	/*Generating map*/
	create_map(map);

		/*SPIECES CHOOSE PART*/
		map->labels = gtk_label_new("SPIECES"); 
		gtk_fixed_put(GTK_FIXED(map->game_window), map->labels, 610, 100);
		map->spiece_choose = gtk_combo_box_new_text(); 
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "PLANT");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "HERBIVORE");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "CARNIVORE");
		gtk_widget_set_size_request(map->spiece_choose, 100, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->spiece_choose, 600, 120);
		
		/*START/PAUSE BUTTON PART*/
		map->start_button = gtk_toggle_button_new_with_label("START"); 
		gtk_widget_set_size_request(map->start_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->start_button, 600, 300);
		
		/*STOP BUTTON PART*/
		map->stop_button = gtk_button_new_with_label("STOP"); 
		gtk_widget_set_size_request(map->stop_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->stop_button, 600, 370);

	g_signal_connect(G_OBJECT(map->window), "destroy", G_CALLBACK(free_mem), NULL);		
	g_signal_connect(G_OBJECT(map->window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all (map->window);
	gtk_main ();
return 0;
}
