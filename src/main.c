// System headers
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// My headers
#include <minesweeper.h>

int main(int argc, char **argv) {
	game_args_t *args = read_args(argc, argv);
	if(args != NULL) {
		double coverage = 100.0 * args->mines / (args->width * args->height);
		printf(
			"%-16s:\n%-16s: %4d\n%-16s: %4d\n%-16s: %4d\n%-16s: %7.2f\%\n", 
			"Board stats",
			"Width", args->width, 
			"Height", args->height, 
			"Mines", args->mines, 
			"Mine coverage", coverage
		);
		free(args);
	}
	return EXIT_SUCCESS;
}