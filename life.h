typedef struct{
	GtkWidget *window;
	GtkWidget *menu;
	GtkWidget *spiece_choose;
	GtkWidget *start_button, *stop_button;
	GtkWidget *labels;

int 	n_xy, /*Declares size of map in x and y direction*/
	*buf,
	*map,
	map_size;
int	day;
} Maps;

void MAIN(GtkWidget *a, gpointer b);

void play_game(Maps *);
void create_buf(Maps *);
void cp_mapbuf(Maps *);
void printmap(GtkWidget *game_window, Maps *);

void create_map(Maps *);
