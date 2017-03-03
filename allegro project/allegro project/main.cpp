#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

int main() {

	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);
	al_clear_to_color(al_map_rgb(150, 0, 215));

	al_flip_display();

	al_rest(50.0);

	al_destroy_display(display);

	return 0;
}