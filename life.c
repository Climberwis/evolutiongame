#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void hypo_move(Maps *);
int next_step(int, int);
int set_state(Maps *, int, int);
void plant_add(Maps *, int);

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
	int i, j, plant=0, carn=0, herb=0;
	for(i=0;i<=9999;i++){
		maps->field[i].moved = 0;
		if(maps->field[i].value == 1){
			plant++;
			maps->field[i].life-=2;
			if(maps->field[i].life<=0) maps->field[i].value=0;
		}
	}
	for(i=0;i<=9999;i++){
	if(!(maps->field[i].value == 0 || maps->field[i].value == 1) && maps->field[i].moved == 0){
		j = rand()%8;
		j=next_step(i, j);
		j = set_state(maps, i, j);
		maps->field[j].moved = 1;
			if(maps->field[j].value==3)maps->field[j].life=maps->field[i].life-1;
			else if(maps->field[j].value==5)maps->field[j].life=maps->field[i].life-4;
		if(maps->field[j].life<=0) maps->field[j].value=0;
		if(maps->field[j].value == 3) herb++;
		else if(maps->field[j].value == 5) carn++;
	}}
plant_add(maps, plant);
g_print("day: %d plant: %d herb: %d carn %d\n", maps->day_timer, plant, herb, carn);
}

int next_step(int i, int j){	
/*DECIDE WHERE NEXT STEP*/		
	if(j<3){
		if(i<=99) j = 9899+i+j;
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
return j;
}

int set_state(Maps *maps, int i, int j){	
	/*DECIDE WHAT HAPPENS ON FIELD*/
	if(maps->field[j].value == 0){
		maps->field[j].value = maps->field[i].value;
		maps->field[i].value=0;
		return j;
	}
	else if(maps->field[j].value==maps->field[i].value){
		if(maps->field[j].life>100 && maps->field[i].life>100){
			int l = rand()%8;
			if(maps->field[next_step(j, l)].value==0){
				maps->field[l].value=maps->field[j].value;
				maps->field[l].life=(maps->field[i].life/3)+(maps->field[j].life/3);
				return i;
			}
			else return i;
		}
		else return i;	
	}
	else if(abs(maps->field[j].value-maps->field[i].value) == 2){
		if(maps->field[j].value>maps->field[i].value){
			maps->field[j].life+=maps->field[i].life;
			maps->field[j].value=maps->field[i].value+2;
			maps->field[i].value=0;
			return i;
		}
		else{
			maps->field[i].life+=maps->field[j].life;
			maps->field[j].value=maps->field[i].value;
			maps->field[i].value=0;
			return j;
		}		
	}
	else if(abs(maps->field[j].value-maps->field[i].value) == 4){
		if(!(maps->field[i].moved == 2)){		
			maps->field[i].moved = 2;
			j = rand()%8;
			j = set_state(maps, i, next_step(i,j));
		}
		else return i;
	}
return j;
}

void plant_add(Maps *maps, int quant){
if(!(maps->day_timer%7)){
	int j;
	int plant = quant/2;
	if (quant > 4000) return;
	else{
		while(plant>0){
			j = rand()%10000;
			if(maps->field[j].value==0){
				maps->field[j].value=1;
				plant--;
			}
			else continue;
		}
	}
}
else return;
	

}
