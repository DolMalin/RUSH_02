#include "rush_02.h"

void	init_board(t_board *board)
{
	int	i;
	int	j;


	i = 0;
	board->content = gc_malloc(sizeof(int*) * board->height);
	while (i < board->height)
	{
		j = 0;
		board->content[i] = gc_malloc(sizeof(int) * board->width);
		while (j < board->width)
		{
			board->content[i][j] = 0;
			j++;
		}
		i++;
	}
}
