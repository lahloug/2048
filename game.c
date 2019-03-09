#include "game.h"
#include <stdio.h>
#include <stdlib.h>

short** new_board()
{
	short **board = malloc(sizeof(short*) * 4);
	for (int i=0; i < 4; i++)
	{
		board[i] = malloc(4 * sizeof(short));
		for (int j=0; j < 4; j++)
		{
			board[i][j] = 0;
		}	
	}
	return board;
}

void print_board(short** board)
{
    for (int i=0; i < 4; i++)
    {
    	for (int j=0; j < 4; j++)
    	{
    		printf("%d ", board[i][j]);
    	}	
	printf("\n");
    }
}
