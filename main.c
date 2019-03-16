#include <stdio.h>
#include "game.h"

int main()
{
	short board[4][4];
	short tile = 2;
	new_game_board(board);
	add_random_tile(tile, board);
	print_board(board);
	return 0;
}
