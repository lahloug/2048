#include <stdio.h>
#include "game.h"

int main()
{
	int board[4][4];
	int tile = 2;
	new_game_board(board);
	print_board(board);
	printf("\n");
	move_board_left(board);
	print_board(board);
	printf("\n");
	move_board_left(board);
	print_board(board);
	return 0;
}
