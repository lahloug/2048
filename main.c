#include <stdio.h>
#include "game.h"

int main()
{
	int board[4][4];
	int tile = 2;
	new_game_board(board);
	print_board(board);
	printf("\n");
	move_board(board, 'r');
	print_board(board);
	printf("\n");
	move_board(board, 'r');
	print_board(board);
	printf("\n");
	move_board(board, 'd');
	print_board(board);
	printf("\n");
	move_board(board, 'd');
	print_board(board);
	printf("\n");
	move_board(board, 'd');
	print_board(board);
	printf("\n");
	move_board(board, 'u');
	print_board(board);
	printf("\n");
	move_board(board, 'l');
	print_board(board);
	printf("\n");
	return 0;
}
