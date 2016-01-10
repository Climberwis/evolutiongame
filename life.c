#include<stdlib.h>
#include<unistd.h>
#include<gtk/gtk.h>
#include"life.h"


void play_game(Maps *maps){
create_buf(maps);
cp_mapbuf(maps);
int i=0, j=0;
for(i=0;i<255;i++){
	for(j=0;j<255;j++)
	continue;
	}
}

void create_buf(Maps *maps){}

void cp_mapbuf(Maps *maps){}

void czerwo(Maps *maps, int pole){
	gtk_image_set_from_file(maps->field[pole].image, "img/carnivore.png");
}
