typedef struct{
	GtkWidget *window, *game_window;
	GtkWidget *game_field;
	GtkWidget *spiece_choose;
	GtkWidget *start_button, *stop_button;
	GtkWidget *labels;

int 	n_xy, /*Declares size of map in x and y direction*/
	buf2,	
	map_size;
char	*buf,
	*map;
int	day;
} Maps;

void MAIN(GtkWidget *a, gpointer b);

void play_game(Maps *);
void create_buf(Maps *);
void cp_mapbuf(Maps *);
void printmap(Maps *);

void create_map(Maps *);
