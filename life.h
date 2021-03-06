typedef struct{
	GtkImage *image;
	int 	value,
		moved;
	double	life;
} MapField;


typedef struct{
	MapField *field;
	GtkWidget *window, *event_box, *game_window;
	GdkPixbuf *land, *herb, *carn, *plant;
	GtkWidget *spiece_choose, *rand_game, *new_game, *start_button, *stop_button, *labels, *creat, *day;
gint	spiece;
int 	day_timer,
	n_xy;
} Maps;

void play_game(Maps *);
