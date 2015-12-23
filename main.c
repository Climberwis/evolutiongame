#include<stdio.h>
#include<gtk/gtk.h>
#include"life.h"

int main(int argc, char *argv[]){
	GtkWidget *window;
	gtk_init (&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 640);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title (GTK_WINDOW(window), "Small Game of Evolution");

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all (window);
	gtk_main ();
return 0;
}
