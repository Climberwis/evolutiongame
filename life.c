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
	for(x=0; x<maps->n_xy; x++){
		for(y=0; y<maps->n_xy; y++){
			if(maps->map[i] == 'l'){
			maps->game_creat = gtk_image_new_from_file("img/land.png");
			gtk_widget_set_size_request(maps->game_creat, 2, 2);
			gtk_fixed_put(GTK_FIXED(maps->game_window), maps->game_creat, 20+2*x, 100+2*y);
			i++;
			}
			}
		}
		

}
