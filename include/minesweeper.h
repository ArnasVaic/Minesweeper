#ifndef MINESWEEPER_H
#define MINESWEEPER_H

// System headers
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// Structure for initial game arguments
typedef struct game_args_t {
	uint16_t width;
	uint16_t height;
	uint16_t mines;
} game_args_t;

// option table
extern game_args_t option_table[3];

// Standard difficulty levels
typedef enum difficulty_t { 
	DIF_NONE = -1, 
	DIF_BEGINNER, 
	DIF_INTERMEDIATE, 
	DIF_EXPERT
} difficulty_t;

// Standard difficulty parameters
// Beginner 
#define BEGINNER_WIDTH		9
#define BEGINNER_HEIGHT		9
#define BEGINNER_MINES		10
// Intermediate
#define INTERMEDIATE_WIDTH	16
#define INTERMEDIATE_HEIGHT	16
#define INTERMEDIATE_MINES	40
// Expert
#define EXPERT_WIDTH		30
#define EXPERT_HEIGHT		16
#define EXPERT_MINES		99

// Custom mode limitations
#define MAX_BOARD_SIDE_LENGTH	1000 

// Prints a message to stdout about provided args.
// Returns a dynamically allocated args_t object if 
// args were valid. In case of failure returns NULL
game_args_t* read_args(int argc, char **argv);

// Returns a dynamically allocated args_t object based on selected difficulty.
// In case of failure returns NULL.
// Note: at the top of the file all difficulty parameters are listed
game_args_t* create_game_args(difficulty_t difficulty);

// Returns a dynamically allocated args_t object based custom settings.
// In case of failure returns NULL.
game_args_t* create_custom_game_args(uint16_t width, uint16_t height, uint16_t mines);

#endif /* MINESWEEPER_H */