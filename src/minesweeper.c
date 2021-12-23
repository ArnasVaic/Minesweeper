#include <minesweeper.h>

game_args_t option_table[3] = {
	{	
		BEGINNER_WIDTH, 
		BEGINNER_HEIGHT, 
		BEGINNER_MINES
	},
	{
		INTERMEDIATE_WIDTH, 
		INTERMEDIATE_HEIGHT, 
		INTERMEDIATE_MINES
	},
	{
		EXPERT_WIDTH, 
		EXPERT_HEIGHT, 
		EXPERT_MINES
	}
};

game_args_t* create_game_args(difficulty_t difficulty) {
	game_args_t *args = (game_args_t*) malloc(sizeof(game_args_t));
	if (args == NULL) {
		printf("Fatal error, could not allocate memory.");
		return NULL;
	}
	*args = option_table[(uint8_t) difficulty];
	return args;
}

game_args_t* create_custom_game_args(uint16_t width, uint16_t height, uint16_t mines) {
	game_args_t *args = (game_args_t*) malloc(sizeof(game_args_t));
	if (args == NULL) {
		printf("Fatal error, could not allocate memory.");
		return NULL;
	}
	args->width = width;
	args->height = height;
	args->mines = mines;
	return args;
}

game_args_t* read_args(int argc, char **argv) {
	if (argc == 4) {	
		long values[3];
		// 1 byte is enough as this loop is ever gonna loop 3 times
		for (uint8_t i = 1; i < argc; ++i) {
			// expect input in decimal format
			char *end_ptr;
			long val = strtol(argv[i], &end_ptr, 10);
			if((*end_ptr != '\0') || (end_ptr == argv[i]) || (val < 0)) {
				printf("Invalid arguments, all arguments should be positive integers");
				return NULL;
			}
			uint8_t bound_val = (val == LONG_MIN) || (val == LONG_MAX);
			if(bound_val && (errno == ERANGE)) {
				printf("Provided values are out of range, please try again");
				return NULL;
			}
			values[i - 1] = val;
		}	
		// check more
		if((values[0] > MAX_BOARD_SIDE_LENGTH) || (values[1] > MAX_BOARD_SIDE_LENGTH)) {
			printf("Provided values are out of range, please try again");
			return NULL;
		}
		// values are successfully read
		return create_custom_game_args(values[0], values[1], values[2]);
	} 
	else if (argc == 1) {
		printf("For more details pass it the help argument [?]");
	} 
	else if (argc == 2) {
		if (strcmp(argv[1], "?") == 0) {
			printf(
				"A single player logic game, where in order to win, you need to find all mines without exploding them.\n"
				"usage: ./Minesweeper <difficulty> (possible difficulties are: beginner, intermediate and expert)\n"
				"for custom setting use: ./Minesweeper <board_width> <board_height> <number_of_mines>"
			);
		}
		difficulty_t dif = DIF_NONE;
		if 		(strcmp(argv[1], "beginner"		) == 0) dif = DIF_BEGINNER;
		else if (strcmp(argv[1], "intermediate"	) == 0) dif = DIF_INTERMEDIATE;
		else if (strcmp(argv[1], "expert"		) == 0)	dif = DIF_EXPERT;
		else {
			printf("Invalid argument");
			return NULL;
		}

		return create_game_args(dif);
		
	} else {
		printf("Invalid number of arguments");
	}	
	return NULL;
}