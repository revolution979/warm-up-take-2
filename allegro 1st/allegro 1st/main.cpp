#include <stdio.h>

#include <allegro5/allegro.h>

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;

	al_init();

	display = al_create_display(640, 480);

	al_clear_to_color(al_map_rgb(150, 0,215));

	al_flip_display();

	al_rest(50.0);

	al_destroy_display(display);

	return 0;
}