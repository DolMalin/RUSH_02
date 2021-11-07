#include "rush_02.h"

void	init_params(t_board *board, t_player *player, t_player *opponent)
{
	get_param(&board->width);
	get_param(&board->height);
	get_param(&board->win_len);
	get_param(&player->starting_position);
	get_param(&board->total_time);
	get_param(&board->time_gain);
	if (player->starting_position == 1)
		opponent->starting_position = 2;
	else
		opponent->starting_position = 1;
	opponent->time = board->total_time;
	player->time = board->total_time;

}
