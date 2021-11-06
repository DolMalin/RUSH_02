#ifndef RUSH_02_H
# define RUSH_02_H

/* ==================== INCLUDES ==================== */

#include <unistd.h>
#include <stdlib.h>

#include "../libft/libft.h"

/* ==================== STRUCTURES ==================== */

typedef struct	s_board
{
	int	width;
	int	height;
	int	win_len;
	int	total_time;
	int	time_gain;
}				t_board;

typedef struct	s_player
{
	int	starting_position;
	int	time;
}				t_player;

#endif
