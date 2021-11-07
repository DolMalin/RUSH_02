#include "rush_02.h"

int	get_first_player(t_player *player, t_player *opponent)
{
	if (player->starting_position == 1)
	{
		player->can_play = 1;
		opponent->can_play = 0;
		return (1);
	}
	player->can_play = 0;
	opponent->can_play = 1;
	return (2);
}
