#include "rush_02.h"

void	run_game(t_board *board, t_player *player, t_player *opponent)
{
	get_first_player(player, opponent);
	while (1)
	{
		if (opponent->can_play)
			opponent_move(board, player, opponent);
		if (player->can_play)
			player_move(board, player, opponent);
	}
}
