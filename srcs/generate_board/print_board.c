
#include "rush_02.h"

void	print_board(t_board *board)
{
	int		i;
	int		j;

	i = board->height -1;
	while (i >= 0)
	{
		j = 0;
		while (j <= board->width -1)
		{
			dprintf(1, "%d", board->content[i][j]);
			j++;
		}
		dprintf(1, "\n");
		i--;
	}
	dprintf(1, "\n");
}
