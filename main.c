#include<stdlib.h>
#include<time.h>
#include<gtk/gtk.h>
#include"life.h"
Maps *map;

static void destroy( GtkWidget *widget){
	g_free ( map );
	map=NULL;
	gtk_main_quit ();
}

int play(GtkWidget *widget){
	play_game(map);
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))) return 1;
	else return 0;
}

void next_day( GtkWidget *widget){
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
		gtk_button_set_label(GTK_BUTTON(widget), "PAUSE");
	}
	else gtk_button_set_label(GTK_BUTTON(widget), "PLAY");
	g_timeout_add(750, play, widget); 
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

void new_map( Maps *map){
	int i;
	gtk_label_set_text(map->day, "DAY No. 0");
	map->day_timer=0;
	for (i=0; i<=9999; i++){
	gtk_image_set_from_pixbuf(map->field[i].image, map->land);
	map->field[i].value = 0;
	}
	for (i=0; i<=9999; i++){
	if(!(i%3) && i > 2500 && i < 6500){
	gtk_image_set_from_pixbuf(map->field[i].image, map->herb);
	map->field[i].value = 3;
	map->field[i].life = 50;
	}
	if(!(i%24) && i < 4000){
	gtk_image_set_from_pixbuf(map->field[i].image, map->carn);
	map->field[i].value = 5;
	map->field[i].life = 60;
	}
	if(!(i%5)){
	gtk_image_set_from_pixbuf(map->field[i].image, map->plant);
	map->field[i].value = 1;
	map->field[i].life = 100;
	}}
}

void create_new_map( GtkWidget *widget){
new_map(map);
}

int main(int argc, char *argv[]){
	map = g_malloc ( sizeof( Maps ) );
	map->n_xy = 100;
		
	srand(time(NULL));
	
	gtk_init (&argc, &argv);
	
	map->window = g_object_new( GTK_TYPE_WINDOW, "window-position", GTK_WIN_POS_CENTER,
	"default-width", 800, "default-height", 640, "title", "Little Game of Evolution", "border-width", 5, NULL );
	g_signal_connect (G_OBJECT (map->window), "destroy", G_CALLBACK (destroy), NULL);

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
		
		g_signal_connect (G_OBJECT (map->new_game), "clicked", G_CALLBACK (create_new_map), NULL);		

		/*START/PAUSE BUTTON PART*/
		map->start_button = gtk_toggle_button_new_with_label("PLAY"); 
		gtk_widget_set_size_request(map->start_button, 150, 50);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->start_button, 600, 300);
		map->day = gtk_label_new("DAY No. 0");
		gtk_fixed_put(GTK_FIXED(map->game_window), map->day, 600, 360);
		g_signal_connect (G_OBJECT (map->start_button), "toggled", G_CALLBACK (next_day), NULL);	

		/*LEGEND*/
		map->creat = gtk_image_new_from_file("img/land.png");
		gtk_widget_set_size_request(map->creat, 4, 4);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->creat, 50, 540);
		map->labels = gtk_label_new("LAND"); 
		gtk_fixed_put(GTK_FIXED(map->game_window), map->labels, 60, 535);
		map->creat = gtk_image_new_from_file("img/plant.png");
		gtk_widget_set_size_request(map->creat, 4, 4);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->creat, 50, 560);
		map->labels = gtk_label_new("PLANT"); 
		gtk_fixed_put(GTK_FIXED(map->game_window), map->labels, 60, 555);
		map->creat = gtk_image_new_from_file("img/herbivore.png");
		gtk_widget_set_size_request(map->creat, 4, 4);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->creat, 50, 580);
		map->labels = gtk_label_new("HERBIVORE"); 
		gtk_fixed_put(GTK_FIXED(map->game_window), map->labels, 60, 575);
		map->creat = gtk_image_new_from_file("img/carnivore.png");
		gtk_widget_set_size_request(map->creat, 4, 4);
		gtk_fixed_put(GTK_FIXED(map->game_window), map->creat, 50, 600);
		map->labels = gtk_label_new("CARNIVORE"); 
		gtk_fixed_put(GTK_FIXED(map->game_window), map->labels, 60, 595);

	gtk_widget_show_all (map->window);
	gtk_main ();
	
return 0;
}
