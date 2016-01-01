#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void create_map(Maps *maps){
int size = maps->n_xy*maps->n_xy;
maps->map = (int*)malloc(sizeof(size));
}

void play_game(Maps *maps){
create_buf(maps);
cp_mapbuf(maps);
printmap(maps->game_window, maps);
int i=0, j=0;
for(i=0;i<255;i++)
	for(j=0;j<255;j++)
	continue;
}

void create_buf(Maps *maps){}

void cp_mapbuf(Maps *maps){
int i=0;
	for(i=0;i<=maps->map_size;i++)
	maps->map[i]=maps->buf[i];
}

void printmap(GtkWidget *game_window, Maps *maps){}
