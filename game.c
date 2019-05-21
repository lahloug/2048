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
	add_random_tile(tile1, board);
	add_random_tile(tile2, board);
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

void copy_board(int (*source)[4], int (*destination)[4])
{
	int i;
	for (i=0; i<4; i++)
	{
		copy_row(source[i], destination[i]);
	}
}

void copy_row(int source[4], int destination[4])
{
	int i;
	for (i=0; i<4; i++)
	{
		destination[i] = source[i];
	}
}

void fill_zero(int row[4], int start, char direction)
{
	int i;
	if (direction == 'l')
	{
		for (i=start; i < 4; i++)
		{
			row[i] = 0;
		}
	}
	else if (direction == 'r')
	{
		int array[4];
		i = 0;
		for (i = 0; i < 4 - start; i++)
		{
			array[i] = 0;
		}
		for (i = 4 - start; i < 4; i++)
		{
			array[i] = row[i + start - 4];
		}
		copy_row(array, row);
	}
}

void reverse_row(int row[], int size)
{
	int row_intermediate[4];
	int i;
	for (i = 0; i < size; i++)
	{
		row_intermediate[i] = row[size - i - 1];
	}
	copy_row(row_intermediate, row);
}

void move_row(int row[4], char direction)
{
	// row_intermediate correspond to row without the O's
	int i;
	int row_intermediate[4];
	int row_final[4];
	int n_tiles_intermediate = 0;
	int n_tiles_final = 0;
	for (i=0; i<4; i++)
	{
		if(row[i] != 0)
		{
			row_intermediate[n_tiles_intermediate++] = row[i];
		}
	}
	if (n_tiles_intermediate == 0) {return;}
	if (n_tiles_intermediate == 1)
       	{
		fill_zero(row_intermediate, n_tiles_intermediate, direction);
		copy_row(row_intermediate, row);
		return;
	}
	i = 0;
	// merge neighbour identical number
	if (direction == 'r')
	{
		reverse_row(row_intermediate, n_tiles_intermediate);
	}
	while (i < n_tiles_intermediate - 1)
	{
		if (row_intermediate[i] != row_intermediate[i+1])
		{
			row_final[n_tiles_final++] = row_intermediate[i++];
		}
		else
		{
			row_final[n_tiles_final++] = row_intermediate[i++] + 1;
			i++;
		}
	}
	if (i == n_tiles_intermediate - 1) // Last two numbers were not merged
	{
		row_final[n_tiles_final] = row_intermediate[i];
		n_tiles_final++;
	}
	if (direction == 'r')
	{
		reverse_row(row_final, n_tiles_final);
	}
	fill_zero(row_final, n_tiles_final, direction);
	copy_row(row_final, row);
}


void transpose(int (*board)[4])
{
	int i, j, temp;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < i; j++)
		{
			temp = board[i][j];
			board[i][j] = board[j][i];
			board[j][i] = temp;
		}
	}
}

/* Move the board to the given direction
* direction:
*   _ r for right
*   _ l for left
*   _ u for up
*   _ d for down
*/ 
void move_board(int (*board)[4], char direction)
{
	int i;
	int before[4][4];
	int retranspose = 0;
	copy_board(board, before);
	if (direction == 'u' | direction == 'd')
	{
		transpose(board);
		retranspose = 1;
		direction = (direction == 'u') ? 'l' : 'r'; 
	}
	for (i=0; i < 4; i++)
	{
		move_row(board[i], direction);
	}
	if (retranspose)
	{
		transpose(board);
	}

	if (!is_equal_board(before, board))
	{
		add_random_tile(1, board);
	}
}

void print_row(int row[4])
{
    int i;
    for (i=0; i < 4; i++)
    {
    		printf("%d ", row[i]);
    }
    printf("\n");
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

int is_equal_row(int row1[4], int row2[4])
{
	int i;
	for (i=0; i < 4; i++)
	{
		if (row1[i] != row2[i])
		{
			return 0;
		}
	}
	return 1;
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
				// printf("i : %d:\n", i);
				// printf("j : %d:\n", j);
				// printf("board1[i][j] : %d:\n", board1[i][j]);
				// printf("board2[i][j] : %d:\n", board2[i][j]);
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

int is_lost(int (*board)[4])
{
	char directions[4] = {'r', 'l', 'u', 'p'};
	char direction;
	int board_copy[4][4];
	int i;
	for (i=0; i < 4; i++)
	{
		direction = directions[i];
		copy_board(board, board_copy);
		move_board(board_copy, direction);
		if (!is_equal_board(board, board_copy))
		{
			return 0;
		}
	}
	return 1;
}


void play()
{
	int board[4][4];
	char direction;
	new_game_board(board);
	while (!is_lost(board))
	{
	print_board(board);
	printf("\n");
	scanf(" %c", &direction);
	if (direction != 'u' && direction != 'd' && direction != 'r' && direction != 'l')
	{
		printf("You should chose one of these direction: u, p, r, l. You chose %c", direction);
		continue;
	}
	move_board(board, direction);
	}
}
