#include<stdio.h>


struct Plant{
int energy;
};


struct Herbivore{
int life_energy;
int genes[8];
};


struct Carnivore{
int life_energy;
int genes[8];
};


typedef struct{
int 	n_x,
	n_y, /*Declares size of map in x and y direction*/
	size,
	*buf,
	*map;
int	day;
} Maps;

void create_map(Maps *map);
