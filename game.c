#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void add_random_tile(int tile, int (*board)[4])
{
	// Finding empty cells
	int i, j, n;
	int empty_cells[16][2];
	int n_empty_cells = 0;
	for (i=0; i < 4; i++)
	{
		for (j=0; j<4; j++)
		{
			if (board[i][j] == 0)
			{
				empty_cells[n_empty_cells][0] = i;
				empty_cells[n_empty_cells][1] = j;
				n_empty_cells ++;
			}
		}
	}
	if (n_empty_cells == 0)
	{
		printf("No empty cell found!");
	}
	srand ( time(NULL) );
	n = (rand() % n_empty_cells);
	i = empty_cells[n][0];
	j = empty_cells[n][1];
	if (board[i][j] != 0)
	{
		printf("Overwriting cell!");
	}
	board[i][j] = tile;
}


void add_random_tile_start(int (*board)[4])
{
	// if a tile value is 2^x, we represent it as x
	// 20 % of the time a 4 tile and 2 tile
	// 80 % of the time two 2 tile
	int p;
	srand ( time(NULL) );
	p = rand() % 10;
	int tile1 = 1;
	int tile2;
	tile2 = p < 2 ? 2 : 1;
	// Fill random location
	srand ( time(NULL) );
	p = (rand() % 2);
	if (p == 0)
	{
		add_random_tile(tile1, board);
		add_random_tile(tile2, board);
	}
	else
	{
		add_random_tile(tile2, board);
		add_random_tile(tile1, board);
	}
}

void new_game_board(int (*board)[4])
{
	int i,j;
	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			board[i][j] = 0;
		}
	}
	add_random_tile_start(board);
}

void
print_board(int (*board)[4])
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

int is_equal_board(int (*board1)[4], int (*board2)[4])
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

int frequence(int (*board)[4], int number)
{
	int i, j;
	int found = 0;
	for (i = 0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			if (board[i][j] == number)
			{
				found++;
			}
		}
	}
	return found;
}
