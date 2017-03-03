#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>


int main() {

	al_init();
	al_init_font_addon();
	al_init_primitives_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	ALLEGRO_DISPLAY *display = al_create_display(640, 480);

	ALLEGRO_FONT *font = al_load_ttf_font("Love Letters.ttf", 72, 0);

	al_clear_to_color(al_map_rgb(50, 10, 70));
	al_draw_text(font, al_map_rgb(255, 2, 55), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "merry valentines day");

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);

	return 0;

}