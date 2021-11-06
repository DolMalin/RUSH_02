#include "rush_02.h"

void	get_param(int *dest)
{
	char	*data;

	get_next_line(0, &data);
	*dest = atoi(data);
	free(data);
}

void	init_params(t_board *board_config, t_player *player_config)
{
	get_param(&board_config->width);
	get_param(&board_config->height);
	get_param(&board_config->win_len);
	get_param(&player_config->starting_position);
	get_param(&board_config->total_time);
	get_param(&board_config->time_gain);
}
