
#include "rush_02.h"

void	get_param(int *dest)
{
	char	*data;

	get_next_line(0, &data);
	*dest = ft_atoi(data);
	free(data);
}