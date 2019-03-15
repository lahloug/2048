#include <stdio.h>
#include "game.h"

int main()
{
	short board[4][4];
	new_game_board(board);
	print_board(board);
	return 0;
}
