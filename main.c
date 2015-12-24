#include<stdio.h>
#include<gtk/gtk.h>
#include"life.h"

int main(int argc, char *argv[]){
	Maps *map;
	map = g_malloc ( sizeof( Maps ) );

	gtk_init (&argc, &argv);

	map->window = g_object_new( GTK_TYPE_WINDOW, "window-position", GTK_WIN_POS_CENTER,
	"default-width", 800, "default-height", 640, "title", "Small Game of Evolution", "border-width", 5, NULL );
	/*Generating map*/

	/*Creating Menu*/
		map->menu_polozenie = gtk_alignment_new( 1, 0.25, 0.1, 0.1 );
		map->menu = gtk_vbox_new(FALSE, 1);
		map->spiece_name = gtk_label_new("Choose the spieces:");
		gtk_container_add(GTK_CONTAINER(map->menu), map->spiece_name);
		map->spiece_choose = gtk_combo_box_new_text();
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "PLANT");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "HERBIVORE");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "CARNIVORE");
		gtk_container_add(GTK_CONTAINER(map->menu), map->spiece_choose);
		map->map_size = gtk_label_new("Map size:");
		gtk_container_add(GTK_CONTAINER(map->menu), map->map_size);
		map->size = gtk_combo_box_new_text();
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->size), "100x100");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->size), "200x200");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->size), "300x300");
		gtk_container_add(GTK_CONTAINER(map->menu), map->size);
		map->start_button = g_object_new( GTK_TYPE_TOGGLE_BUTTON, "label", "START", NULL );
		map->stop_button = g_object_new( GTK_TYPE_BUTTON, "label", "STOP", NULL);
		gtk_box_pack_start (GTK_BOX(map->menu), map->start_button, TRUE, TRUE, 0);
		gtk_box_pack_start (GTK_BOX(map->menu), map->stop_button, TRUE, TRUE, 0);
		gtk_container_add(GTK_CONTAINER(map->window), map->menu_polozenie);
		gtk_container_add(GTK_CONTAINER(map->menu_polozenie), map->menu);

	g_signal_connect(G_OBJECT(map->window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all (map->window);
	gtk_main ();
return 0;
}
