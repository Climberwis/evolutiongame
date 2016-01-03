#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void create_map(Maps *maps){
int i;
maps->map_size = maps->n_xy*maps->n_xy;
maps->map = (char*)malloc(maps->map_size*sizeof(maps->map));
	for(i=0;i<=maps->map_size;i++){
	maps->map[i] = 'l';
	}
printmap(maps);
free(maps->map);
maps->map=NULL;
}

void play_game(Maps *maps){
create_buf(maps);
cp_mapbuf(maps);
printmap(maps);
int i=0, j=0;
for(i=0;i<255;i++){
	for(j=0;j<255;j++)
	continue;
	}
}

void create_buf(Maps *maps){}

void cp_mapbuf(Maps *maps){
int i=0;
	for(i=0;i<=maps->map_size;i++)
	maps->map[i]=maps->buf[i];
}

void printmap(Maps *maps){
int i=0, x, y;
	for(y=0; y<=maps->n_xy-1; y++){
		for(x=0; x<=maps->n_xy-1; x++){
			if(maps->map[i] == 'l'){
			maps->game_field = gtk_image_new_from_file("img/land.png");
			}
			else if(maps->map[i] == 'c'){
			maps->game_field = gtk_image_new_from_file("img/carnivore.png");
			}
			else if(maps->map[i] == 'h'){
			maps->game_field = gtk_image_new_from_file("img/herbivore.png");
			}
			else if(maps->map[i] == 'p'){
			maps->game_field = gtk_image_new_from_file("img/plant.png");
			}
			else{
			break;
			}
			gtk_widget_set_size_request(maps->game_field, 4, 4);
			gtk_fixed_put(GTK_FIXED(maps->game_window), maps->game_field, 50+4*x, 120+4*y);
			i++;
			}
		}
}
