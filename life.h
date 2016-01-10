
typedef struct{
	GtkImage *image;
	int value;
} MapField;


typedef struct{
	MapField *field;
	GtkWidget *window, *game_window;
	GdkPixbuf *land, *herb, *carn, *plant;
	GtkWidget *spiece_choose, *new_game, *start_button, *stop_button, *labels;
int 	day,
	n_xy;
} Maps;

void play_game(Maps *);
