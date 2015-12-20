#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"life.h"

void create_map(Maps *map){
map->size=map->n_x*map->n_y;
map->buf=(int*)malloc(map->size*sizeof(int));
map->map=(int*)malloc(map->size*sizeof(int));
}
