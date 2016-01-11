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

void next_day( GtkWidget *widget, gpointer  pmap ){
	Maps *maps = pmap;
	play_game(maps);
}
	
void init_map(Maps *maps){
	maps->field=calloc(10000,sizeof(MapField));
	int i, j=0, x, y;
	maps->day_timer = 0;
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

void new_map( GtkWidget *widget, gpointer  pmap ){
	Maps *maps = pmap;
	int i;
	gtk_label_set_text(maps->day, "DAY No. 0");
	maps->day_timer=0;
	for (i=0; i<=9999;i++){
	gtk_image_set_from_pixbuf(maps->field[i].image, maps->land);
	maps->field[i].value = 0;
	}
	gtk_image_set_from_pixbuf(maps->field[220].image, maps->plant);
	maps->field[220].value = 1;
	maps->field[220].life = 50;
	gtk_image_set_from_pixbuf(maps->field[221].image, maps->plant);
	maps->field[221].value = 1;
	maps->field[221].life = 50;
	gtk_image_set_from_pixbuf(maps->field[321].image, maps->plant);
	maps->field[321].value = 1;
	maps->field[321].life = 50;
	gtk_image_set_from_pixbuf(maps->field[421].image, maps->plant);
	maps->field[421].value = 1;
	maps->field[421].life = 50;
	gtk_image_set_from_pixbuf(maps->field[420].image, maps->plant);
	maps->field[420].value = 1;
	maps->field[420].life = 50;
	gtk_image_set_from_pixbuf(maps->field[320].image, maps->carn);
	maps->field[320].value = 5;
	maps->field[320].life = 20;
	gtk_image_set_from_pixbuf(maps->field[319].image, maps->herb);
	maps->field[319].value = 3;
	maps->field[319].life = 25;
}

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
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "LAND");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "PLANT");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "HERBIVORE");
		gtk_combo_box_append_text(GTK_COMBO_BOX(map->spiece_choose), "CARNIVORE");
		gtk_widget_set_size_request(map->spiece_choose, 100, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->spiece_choose, 600, 120);

		/*NEW GAME BUTTON PART*/
		map->new_game = gtk_button_new_with_label("NEW"); 
		gtk_widget_set_size_request(map->new_game, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->new_game, 600, 230);
		
		g_signal_connect (G_OBJECT (map->new_game), "clicked", G_CALLBACK (new_map), map);		

		/*START/PAUSE BUTTON PART*/
		map->start_button = gtk_button_new_with_label("NEXT_DAY"); 
		gtk_widget_set_size_request(map->start_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->start_button, 600, 300);
		map->day = gtk_label_new("DAY No. 0");
		gtk_fixed_put(GTK_FIXED(map->game_window), map->day, 600, 360);
		g_signal_connect (G_OBJECT (map->start_button), "clicked", G_CALLBACK (next_day), map);	
		
	gtk_widget_show_all (map->window);
	gtk_main ();
	
return 0;
}
