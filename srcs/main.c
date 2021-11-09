#include <stdio.h>
#include "rush_02.h"

int main() {
	t_list		*gc = NULL;
	t_board		*board = malloc_gc(&gc, sizeof(t_board));
	t_player	*player = malloc_gc(&gc, sizeof(t_player));
	t_player	*opponent = malloc_gc(&gc, sizeof(t_player));

	init_params(board, player, opponent);
	init_board(board, gc);
	run_game(board, player, opponent, gc);
	//run_game_test(board, player, opponent, gc);
	ft_lstclear(&gc, free);
}


