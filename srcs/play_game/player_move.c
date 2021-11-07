#include "rush_02.h"

void	player_move(t_board *board, t_player *player, t_player *opponent, t_list *gc)
{
	int col = minimax(board, player, gc);
	printf("%d\n", col);
	fflush(stdout);
	if (find_row_position(board->content, board->height, col) != -1)
		board->content[find_row_position(board->content, board->height, col)][col] = player->starting_position;
	player->can_play = 0;
	opponent->can_play = 1;
}
