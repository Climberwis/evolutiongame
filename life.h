typedef struct{
	GtkWidget 	*window;
	GtkWidget *menu, *menu_polozenie;
	GtkWidget *spiece_choose, *spiece_name;
	GtkWidget *size, *map_size, *start_button, *stop_button;

int 	n_x,
	n_y, /*Declares size of map in x and y direction*/
	*buf,
	*map;
int	day;
} Maps;
