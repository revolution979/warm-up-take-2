#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

int main() {

	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);

}