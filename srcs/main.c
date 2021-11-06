#include <stdio.h>
#include "rush_02.h"



int main() {
	t_list *gc;
	t_board		*board = malloc_gc(&gc, sizeof(t_board));
	t_player	*player1 = malloc_gc(&gc, sizeof(t_player));
//	t_player	player2;


	init_params(board, player1);
	printf("width : %d\n", board->width);
	ft_lstclear(&gc, free);
}
