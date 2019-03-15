#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_game_board(short (*board)[4])
{
	int i,j;
	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			board[i][j] = 0;
		}
	}
}

void
print_board(short (*board)[4])
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

int is_equal_board(short (*board1)[4], short (*board2)[4])
{
	int i;
	for(i=0; i < 4; i++)
	{
		int j;
		for (j=0; j < 4; j++)
		{
			if (board1[i][j] != board2[i][j])
			{
				printf("i : %d:\n", i);
				printf("j : %d:\n", j);
				printf("board1[i][j] : %d:\n", board1[i][j]);
				printf("board2[i][j] : %d:\n", board2[i][j]);
				return 0;
			}
		}
	}
	return 1;
}
