#include "rush_02.h"

int	get_first_player(t_player *player1)
{
	if (player1->starting_position == 1)
	{
		player1->can_play = 1;
		return (1);
	}
	player1->can_play = 0;
	return (2);
}
