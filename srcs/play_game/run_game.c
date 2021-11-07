#include "rush_02.h"

_Noreturn void	run_game(t_board *board, t_player *player, t_player *opponent, t_list *gc)
{
	get_first_player(player, opponent);
	while (1)
	{
		if (opponent->can_play) {
			opponent_move(board, player, opponent);
//			print_board(board);
		}
		if (player->can_play) {
			player_move(board, player, opponent, gc);
//			print_board(board);
		}
	}
}

void run_game_test(t_board *board, t_player *player, t_player *opponent, t_list *gc) {
	board->width = 7;
	board->height = 7;
	board->win_len = 4;
	player->starting_position = 1;
	board->total_time = 1000;
	if (player->starting_position == 1)
		opponent->starting_position = 2;
	else
		opponent->starting_position = 1;
	opponent->time = board->total_time;
	player->time = board->total_time;
	get_first_player(player, opponent);

	int line7[] = {0, 0, 0, 1, 0, 0, 0};
	int line6[] = {0, 0, 0, 2, 0, 0, 0};
	int line5[] = {0, 0, 1, 1, 0, 0, 0};
	int line4[] = {0, 0, 2, 2, 0, 0, 0};
	int line3[] = {0, 0, 1, 1, 0, 0, 0};
	int line2[] = {0, 0, 2, 2, 0, 0, 0};
	int line1[] = {0, 0, 1, 1, 0, 0, 0};

	init_board(board, gc);
	board->content[0] = line1;
	board->content[1] = line2;
	board->content[2] = line3;
	board->content[3] = line4;
	board->content[4] = line5;
	board->content[5] = line6;
	board->content[6] = line7;
	print_board(board);
	player_move(board, player, opponent, gc);
	print_board(board);
}
