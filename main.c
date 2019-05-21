#include <stdio.h>
#include "game.h"

int main()
{
	int board[4][4];
	int tile = 2;
	char directions[4] = {'r', 'l', 'u', 'd'};
	char direction;
	int i, j;
	new_game_board(board);
	print_board(board);
	for (i=0; i<1000; i++)
	{
		for (j=0; j<4; j++)
		{
			direction = directions[j];
			move_board(board, direction);
			print_board(board);
			printf("\n");
			printf("game is lost: %d", is_lost(board));
			printf("\n");
		}
	}
	return 0;
}
