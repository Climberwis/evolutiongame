#include<stdlib.h>
#include<unistd.h>
#include<gtk/gtk.h>
#include"life.h"

void create_buf(Maps *);
void copy_on_screen(Maps *);
void hypo_move(Maps *);
void set_state(Maps *);


void play_game(Maps *maps){
create_buf(maps);
copy_on_screen(maps);
}

void copy_on_screen(Maps *maps){
int i;
	for(i=0;i<=9999;i++){
	if(maps->field[i].value == 0) gtk_image_set_from_pixbuf(maps->field[i].image, maps->land);
	if(maps->field[i].value == 1) gtk_image_set_from_pixbuf(maps->field[i].image, maps->plant);
	if(maps->field[i].value == 3) gtk_image_set_from_pixbuf(maps->field[i].image, maps->herb);
	if(maps->field[i].value == 5) gtk_image_set_from_pixbuf(maps->field[i].image, maps->carn);
	}
}

void create_buf(Maps *maps){
hypo_move(maps);
set_state(maps);
}

void hypo_move(Maps *maps){

}

void set_state(Maps *maps){}
