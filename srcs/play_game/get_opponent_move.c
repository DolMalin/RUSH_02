#include "rush_02.h"

int	get_opponent_move(void)
{
	char	*data;

	get_next_line(0, &data);
	return (ft_atoi(data));
}