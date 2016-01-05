typedef struct{
	GtkImage *image;
	int *value;
} MapField;


typedef struct{
	MapField field[10000];
	GtkWidget *window, *game_window;
	GtkWidget *spiece_choose, *new_game, *start_button, *stop_button, *labels;
int 	n_xy, /*Declares size of map in x and y direction*/
	buf2,	
	map_size;
char	*buf;
} Maps;



void MAIN(GtkWidget *a, gpointer b);

void play_game(Maps *);
void create_buf(Maps *);
void cp_mapbuf(Maps *);
