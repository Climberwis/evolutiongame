typedef struct{
	GtkWidget *window, *game_window, *game_window_polozenie;
	GtkWidget *menu, *menu_polozenie, *table;
	GtkWidget *spiece_choose, *spiece_name;
	GtkWidget *size, *map_size, *start_button, *stop_button;

int 	n_xy, /*Declares size of map in x and y direction*/
	*buf,
	*map;
int	day;
} Maps;




void MAIN(GtkWidget *a, gpointer b);

void play_game(Maps *);
void create_buf(Maps *);
void cp_mapbuf(Maps *);
void printmap(GtkWidget *game_window, Maps *);

void create_map(Maps *);



