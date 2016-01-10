#include<stdlib.h>
#include<time.h>
#include<gtk/gtk.h>
#include"life.h"

static void destroy( GtkWidget *widget, gpointer  pmap ){
	Maps *maps = pmap;
	g_free ( maps );
	maps=NULL;
	gtk_main_quit ();
}

void new_game1( GtkWidget *widget, gpointer  pmap ){
	Maps *maps = pmap;
	int i;
	for(i=0;i<=9999;i++){
	if(!(i%3)) gtk_image_set_from_pixbuf(maps->field[i].image, maps->carn);
	if(!(i%5)) gtk_image_set_from_pixbuf(maps->field[i].image, maps->herb);
	if(!(i%7)) gtk_image_set_from_pixbuf(maps->field[i].image, maps->plant);
	}
}
	
void init_map(Maps *maps){
	maps->field=calloc(10000,sizeof(MapField));
	int i, j=0, x, y;
	for (i=0; i<=9999;i++){
		maps->field[i].image = gtk_image_new_from_file("img/land.png");
		maps->field[i].value = 0;
	}
	for(y=0; y<=maps->n_xy-1; y++){
		for(x=0; x<=maps->n_xy-1; x++){
		gtk_widget_set_size_request(maps->field[j].image, 4, 4);
		gtk_fixed_put(GTK_FIXED(maps->game_window), maps->field[j].image, 50+4*x, 120+4*y);
		j++;
	}
	}
	maps->land=gdk_pixbuf_new_from_file("img/land.png", NULL);
	maps->herb=gdk_pixbuf_new_from_file("img/herbivore.png", NULL);
	maps->carn=gdk_pixbuf_new_from_file("img/carnivore.png", NULL);
	maps->plant=gdk_pixbuf_new_from_file("img/plant.png", NULL);
}

void init( GtkWidget *widget, gpointer  pmap ){
	Maps *maps = pmap;
	int i;
	for (i=0; i<=9999;i++){
	gtk_image_set_from_pixbuf(maps->field[i].image, maps->land);
	maps->field[i].value = 0;
}}

int main(int argc, char *argv[]){
	Maps *map;
	map = g_malloc ( sizeof( Maps ) );
	map->n_xy = 100;
		
	srand(time(NULL));
	
	gtk_init (&argc, &argv);
	
	map->window = g_object_new( GTK_TYPE_WINDOW, "window-position", GTK_WIN_POS_CENTER,
	"default-width", 800, "default-height", 640, "title", "Little Game of Evolution", "border-width", 5, NULL );
	g_signal_connect (G_OBJECT (map->window), "destroy", G_CALLBACK (destroy), map);

		/*Creating Menu*/
		map->game_window = gtk_fixed_new(); 
		gtk_container_add(GTK_CONTAINER(map->window), map->game_window);
		
		/*Generating Map*/
		init_map(map);

		/*SPIECES CHOOSE PART*/
		map->labels = gtk_label_new("SPIECES"); 
		gtk_fixed_put(GTK_FIXED(map->game_window), map->labels, 610, 100);
		map->spiece_choose = gtk_combo_box_new_text(); 
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "PLANT");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "HERBIVORE");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "CARNIVORE");
		gtk_widget_set_size_request(map->spiece_choose, 100, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->spiece_choose, 600, 120);

		/*NEW GAME BUTTON PART*/
		map->new_game = gtk_button_new_with_label("NEW"); 
		gtk_widget_set_size_request(map->new_game, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->new_game, 600, 230);
		g_signal_connect (G_OBJECT (map->new_game), "clicked", G_CALLBACK (init), map);		

		/*START/PAUSE BUTTON PART*/
		map->start_button = gtk_button_new_with_label("START"); 
		gtk_widget_set_size_request(map->start_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->start_button, 600, 300);

		/*STOP BUTTON PART*/
		map->stop_button = gtk_button_new_with_label("STOP(INIT)"); 
		gtk_widget_set_size_request(map->stop_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->stop_button, 600, 370);
		g_signal_connect (G_OBJECT (map->stop_button), "clicked", G_CALLBACK (new_game1), map);	
		
	gtk_widget_show_all (map->window);
	gtk_main ();
	
return 0;
}
