#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short** new_board()
{
	short **board = malloc(sizeof(short*) * 4);
	int i;
	for (i=0; i < 4; i++)
	{
		board[i] = malloc(4 * sizeof(short));
		memset(board[i], 0, 4 * sizeof(short));
	}
	return board;
}

void print_board(short** board)
{
    int i;
    for (i=0; i < 4; i++)
    {
	int j;
    	for (j=0; j < 4; j++)
    	{
    		printf("%d ", board[i][j]);
    	}	
	printf("\n");
    }
}
