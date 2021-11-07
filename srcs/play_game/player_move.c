#include "rush_02.h"

void	player_move(t_board *board, t_player *player, t_player *opponent)
{
	char	*data;
	int		move;

	get_next_line(0, &data);
	move = ft_atoi(data);
	put_move_on_board(move, player->starting_position, board);
	player->can_play = 0;
	opponent->can_play = 1;
	print_board(board);
}