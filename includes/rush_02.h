#ifndef RUSH_02_H
# define RUSH_02_H

/* ==================== INCLUDES ==================== */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../libft/libft.h"

/* ==================== STRUCTURES ==================== */

typedef struct	s_board
{
	int	width;
	int	height;
	int	win_len;
	int	total_time;
	int	time_gain;
	int	**content;
}				t_board;

typedef struct	s_player
{
	int	starting_position;
	int	time;
}				t_player;

/* ==================== PROTOTYPES ==================== */

void	init_params(t_board *board_config, t_player *player_config);
void	get_param(int *dest);

void	init_board(t_board *board);
void	print_board(t_board *board);
#endif
