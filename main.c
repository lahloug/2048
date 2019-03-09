#include <stdio.h>
#include "game.h"

int main()
{
	short** board = new_board();
	print_board(board);
	return 0;
}
