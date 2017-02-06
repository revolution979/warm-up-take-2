#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>


int main(int argc) {

	al_init();
	al_init_font_addon();
	al_init_primitives_addon();
	
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);
	ALLEGRO_FONT* font = al_create_builtin_font();
	
	display = al_create_display(800, 600);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_filled_triangle(225, 525, 375, 225,525,525, al_map_rgb(255,255,0));
	al_draw_text(font, al_map_rgb(2,2,2), 370, 370, ALLEGRO_ALIGN_CENTER, "WARNING!!");
	al_draw_text(font, al_map_rgb(2, 2, 2), 370, 500, ALLEGRO_ALIGN_CENTER, "turtles");
	al_flip_display();
	al_rest(15);
	al_destroy_display(display);
}