#include <stdio.h>
#include <allegro5/allegro.h>

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *fish = NULL;

	//here's the bouncer's x and y coordinates on the screen, initally set to 30,30
	float bouncer_x = 30;
	float bouncer_y = 30;

	float fish_x = 610;
	float fish_y = 450;

	//here's the bouncer's x and y directions, initially set to -4, 4
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	float fish_dx = -4.0, fish_dy = 4.0;
	bool redraw = true;

	al_init();

	//set the timer so it "ticks" at 2 milliseconds
	timer = al_create_timer(.02);

	display = al_create_display(640, 480);

	////////////////////////////////////////////
	//create a little 32x32 square
	bouncer = al_create_bitmap(32, 32);
	fish = al_create_bitmap(32, 32);

	//use this to *draw* your own bitmaps (instead of loading them from a file)
	//before we used al_load_bitmap()
	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 100, 100));

	al_set_target_bitmap(fish);
	/////////////////////////////////////////////
	

	
	////////////////////////////////////////////

	//set the color of your bitmap
	al_clear_to_color(al_map_rgb(255, 100, 100));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	//register the timer as an event source so it can generate events
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	(al_map_rgb(0, 0, 0));

	al_flip_display();

	//GUESS WHAT THIS DOES
	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		//this function will wait forever if no events come in
		al_wait_for_event(event_queue, &ev);

		//////////////////////////////////////////////////////////////////////////////////
		//this section handles the bouncing-off-the-edges action

		//sets this part of the game to run on the clicks of the timer 
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//if the box hits the left wall OR the right wall
			if (bouncer_x < 0 || bouncer_x > 640 - 32) {
				//flip the x direction
				bouncer_dx = -bouncer_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (bouncer_y < 0 || bouncer_y > 480 - 32) {
				//flip the y direction
				bouncer_dy = -bouncer_dy;
			}
			///////////////////
			if (fish_x < 0 || fish_x > 640 - 32) {
				//flip the x direction
				fish_dx = -fish_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (fish_y < 0 || fish_y > 480 - 32) {
				//flip the y direction
				fish_dy = -fish_dy;
			}
			///////////////////

			//really important code!
			//move the box in a diagonal
			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;

			fish_x += fish_dx;
			fish_y += fish_dy;

			//if an event happened, you better redraw
			redraw = true;
		}

		//////////////////////////////////////////////////////////////////
		//kill program if the user clicks the exit button
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//if you were supposed to redraw but there wasn't an event, don't redraw
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//al_clear_to_color(al_map_rgb(0, 0, 0));

			//here's where the magic happens: draw the square to the screen
			//at the coordinate position bouncer_x, bouncer_y
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			al_draw_bitmap(fish, fish_x, fish_y, 0);

			al_flip_display();
		}
	}//end game loop

	al_destroy_bitmap(bouncer);
	al_destroy_bitmap(fish);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}