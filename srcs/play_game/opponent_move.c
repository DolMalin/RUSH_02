#include "rush_02.h"

void	opponent_move(t_board *board, t_player *player,  t_player *opponent)
{
	int move;

	move = get_opponent_move();
	put_move_on_board(move, opponent->starting_position, board);
	opponent->can_play = 0;
	player->can_play = 1;
	print_board(board);
}