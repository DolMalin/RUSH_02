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

typedef struct s_info_minimax
{
	int score;
	int col;
}				t_info_minimax;
typedef struct	s_pos
{
	int	row;
	int	col;
}				t_pos;
typedef struct	s_player
{
	int	starting_position;
	int	time;
	int	can_play;
}				t_player;

/* ==================== PROTOTYPES ==================== */

void	init_params(t_board *board, t_player *player, t_player *opponent);
void	get_param(int *dest);

void	init_board(t_board *board, t_list *gc);
void	print_board(t_board *board);

void	get_first_player(t_player *player, t_player *opponent);
int		get_opponent_move(void);
void	opponent_move(t_board *board, t_player *player,  t_player *opponent);
void	put_move_on_board(int move, int player_token, t_board *board);
_Noreturn void	run_game(t_board *board, t_player *player, t_player *opponent, t_list *gc);
void run_game_test(t_board *board, t_player *player, t_player *opponent, t_list *gc);
void	player_move(t_board *board, t_player *player, t_player *opponent, t_list *gc);
int score_to_position(t_board *board, int **board_copy, t_player *player, t_pos *pos_piece);
t_info_minimax score_to_all_position(t_board *board, t_player *player, int **board_copy);
int		minimax(t_board *board, t_player *player, t_list *gc);
int 	score_horizontal(t_board *board, int **board_content, int numero_player, t_pos *pos_piece);
int 	score_vertical(int **board_content, int win_len, int numero_player, t_pos *pos_piece);
int		score_diagonal_right(t_board *board, int **board_content, int board_width, int board_height, int win_len, int numero_player, t_pos *pos_piece);
int 	score_diagonal_left(int **board_content, int board_width, int board_height, int win_len, int numero_player, t_pos *pos_piece);
int		score_middle(int board_width, t_pos *pos_piece);
int find_row_position(int **board_copy, int board_height, int col);
#endif
