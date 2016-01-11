#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void hypo_move(Maps *);
void set_state(Maps *);

void play_game(Maps *maps){
char day_text[80];
maps->day_timer++;
sprintf(day_text,"DAY No. %d",maps->day_timer);
gtk_label_set_text(maps->day, day_text);
hypo_move(maps);
set_state(maps);
int i;
	for(i=0;i<=9999;i++){
	if(maps->field[i].value == 0) gtk_image_set_from_pixbuf(maps->field[i].image, maps->land);
	if(maps->field[i].value == 1) gtk_image_set_from_pixbuf(maps->field[i].image, maps->plant);
	if(maps->field[i].value == 3) gtk_image_set_from_pixbuf(maps->field[i].image, maps->herb);
	if(maps->field[i].value == 5) gtk_image_set_from_pixbuf(maps->field[i].image, maps->carn);
	}
}

void hypo_move(Maps *maps){

}

void set_state(Maps *maps){
int i;
	for(i=0;i<=9999;i++){
	switch(maps->field[i].value) {
		case 0: maps->field[i].value = 0;
			break;
		case 1: maps->field[i].value = 1;
			break;
		case 3: maps->field[i].value = 3;
			break;
		case 4: maps->field[i].value = 3;
			break;
		case 5: maps->field[i].value = 5;
			break;
		case 6: maps->field[i].value = 3;
			break;
		case 8: maps->field[i].value = 5;
			break;
		case 10: maps->field[i].value = 5;
			break;
		}
	}
}
