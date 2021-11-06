
#include "rush_02.h"

void	print_board(t_board *board)
{
	int		i;
	int		j;
	char	buff;
	int		fd;

	fd = open("board.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			buff = board->content[i][j] + '0';
			write(fd, &buff, 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
}
