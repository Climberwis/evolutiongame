#include<stdio.h>
#include"life.h"

int main(){
Maps map;
printf("X & Y size:\t");
scanf("%i %i", &map.n_x, &map.n_y);
create_map(&map);
printf("\nThe size is %i\n", map.size);
return 0;
}
