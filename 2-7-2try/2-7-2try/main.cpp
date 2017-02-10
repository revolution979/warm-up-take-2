#include <allegro5\allegro.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h
#include <stdio.h>

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_SAMPLE *sample = NULL;

	sample = al_load_sample("footstep.wav");
	if (!sample) {
		printf("Audio clip sample not loaded!\n");
		return -1;
	}

	display = al_create_display(640, 480);

	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	/* Loop the sample until the display closes. */
	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	al_rest(10.0);

	al_destroy_display(display);
	al_destroy_sample(sample);
	return 0;
	if(input)
}