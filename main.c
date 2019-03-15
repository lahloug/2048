#include <stdio.h>
#include "game.h"

int main()
{
	short** board = create_empty_board();
	print_board(board);
	return 0;
}
