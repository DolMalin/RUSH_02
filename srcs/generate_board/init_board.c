#include "rush_02.h"

void	init_board(t_board *board, t_list *gc)
{
	int	i;
	int	j;


	i = 0;
	board->content = malloc_gc(&gc, sizeof(int*) * board->height);
	while (i < board->height)
	{
		j = 0;
		board->content[i] = malloc_gc(&gc, sizeof(int) * board->width);
		while (j < board->width)
		{
			board->content[i][j] = 0;
			j++;
		}
		i++;
	}
}
