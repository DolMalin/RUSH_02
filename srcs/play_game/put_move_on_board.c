#include "rush_02.h"

void	put_move_on_board(int move, int player_token, t_board *board)
{
	int	i;

	i = 0;
	while (board->content[i][move] != 0 && i < board->height - 1)
		i++;
	if (i < board->height && board->content[i][move] == 0)
		board->content[i][move] = player_token;
}
