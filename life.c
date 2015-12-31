#include<stdlib.h>
#include<gtk/gtk.h>
#include"life.h"

void create_map(Maps *maps){
int size = maps->n_xy*maps->n_xy;
maps->map = (int*)malloc(sizeof(size));
maps->game_window = gtk_vbox_new(FALSE, 1);
gtk_table_attach_defaults (GTK_TABLE(maps->table), maps->game_window, 0, 1, 0, 1);
}

void play_game(Maps *maps){
create_buf(maps);
cp_mapbuf(maps);
printmap(maps->game_window, maps);
int i=0, j=0;
for(i=0;i<255;i++)
	for(j=0;j<255;j++)
	continue;
}
