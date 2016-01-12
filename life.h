typedef struct{
	GtkImage *image;
	int 	value,
		moved,
		life;
} MapField;


typedef struct{
	MapField *field;
	GtkWidget *window, *game_window;
	GdkPixbuf *land, *herb, *carn, *plant;
	GtkWidget *spiece_choose, *new_game, *start_button, *stop_button, *labels,*day;
int 	day_timer,
	n_xy;
} Maps;

void play_game(Maps *);
