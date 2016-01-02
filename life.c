#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void create_map(Maps *maps){
int size = maps->n_xy*maps->n_xy, i;
maps->map = (char*)malloc(size*sizeof(maps->map));
	for(i=0;i<=size;i++){
	maps->map[i] = 'l';
	}
printmap(maps);
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
	for(x=0; x<=maps->n_xy; x++){
		for(y=0; y<=maps->n_xy; y++){
			if(maps->map[i] == 'l'){
			maps->game_creat = gtk_image_new_from_file("img/land.png");
			i++;
			}
			}
		}
		

}
