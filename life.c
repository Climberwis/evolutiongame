#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void hypo_move(Maps *);
int set_state(Maps *, int, int);

void play_game(Maps *maps){
char day_text[80];
maps->day_timer++;
sprintf(day_text,"DAY No. %d",maps->day_timer);
gtk_label_set_text(maps->day, day_text);
hypo_move(maps);
int i;
	for(i=0;i<=9999;i++){
	if(maps->field[i].value == 0) gtk_image_set_from_pixbuf(maps->field[i].image, maps->land);
	if(maps->field[i].value == 1) gtk_image_set_from_pixbuf(maps->field[i].image, maps->plant);
	if(maps->field[i].value == 3) gtk_image_set_from_pixbuf(maps->field[i].image, maps->herb);
	if(maps->field[i].value == 5) gtk_image_set_from_pixbuf(maps->field[i].image, maps->carn);
	}
}

void hypo_move(Maps *maps){
	int i, j;
	for(i=0;i<=9999;i++){
		maps->field[i].moved = 0;
	}
	for(i=0;i<=9999;i++){
	if(!(maps->field[i].value == 0 || maps->field[i].value == 1) && maps->field[i].moved == 0){/*losuj nowe pole oznaczone j, sprawdź co tam jest*/
		j = rand()%8;
		j = set_state(maps, i, j);
		maps->field[j].value = maps->field[i].value;
		maps->field[i].value=0;
		maps->field[j].moved = 1;
		if((maps->field[j].life=maps->field[i].life-1)==0) maps->field[j].value=0;
	}}
}
int set_state(Maps *maps, int i, int j){	
	g_print("%d \t", j);	
	if(j<3){
		if(i<99) j = 9899+i+j;
		else if(!(i%100) && j == 0) j = i-1;
		else if(!((i+1)%100) && j == 2) j = i-199;
		else j = i-101+j;
	}
	else if(j==3){
		if(!(i%100)) j =i+99;
		else j=i-1;
	}
	else if(j==4){
		if(!((i+1)%100 )) j =i-99;
		else j=i+1;
	}
	else if(i>=9900 && j==6) j = i - 9900;
	else if(j==6) j=i+100;
	else if(j==5 || j == 7){
		if(i==9800 && j == 6) j = 9999;
		else if(i==9999 && j == 7) j = 1;
		else if(i==9900 && j == 5) j = 99;
		else if(i>=9900) j = i-9906+j;		
		else if(!(i%100) && j == 5) j = i + 199;
		else if(!((i+1)%100) && j == 7) j = i + 1;
		else j = i+94+j;
	}
	g_print("%d \n", j);
	if(maps->field[j].value == 0){
	return j;}
	else if(maps->field[j].value==maps->field[i].value){/*Sprawdź czy można stworzyć nowego creata*/}
	else if(abs(maps->field[j].value-maps->field[i].value) == 2){/*Zeżryj to o mniejszym value i przesuń tutaj*/}
	else if(abs(maps->field[j].value-maps->field[i].value) == 4){/*losuj jeszcze raz i wywołaj samego się*/}
return j;
}
