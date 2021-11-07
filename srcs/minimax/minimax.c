#include "rush_02.h"

int score_to_position(t_board *board, t_player *player, t_pos *pos_piece){

	int score;
	score = score_horizontal(board->content, board->width, board->win_len, player->starting_position, pos_piece);
	score += score_vertical(board->content, board->win_len, player->starting_position, pos_piece);
	score += score_diagonal_left(board->content, board->width, board->height, board->win_len, player->starting_position, pos_piece);
	score += score_diagonal_right(board->content, board->width, board->height, board->win_len, player->starting_position, pos_piece);
	score += score_middle(board->width, pos_piece);
	return (score);
}


int find_row_position(int **board_content, int board_height, int col) {

	if (board_content[board_height - 1][col] != 0)
		return -1;
	int pos = 0;
	for (pos = 0 ; pos != board_height && board_content[pos][col] != 0; pos++);
	return pos;
}

int **ft_array_int_dup(int **array, int width, int height, t_list *gc) {
	int **array_dup;

	array_dup = malloc_gc(&gc, sizeof(int*) * height);
	for (int i = 0; i < height; ++i) {
		array_dup[i] = malloc_gc(&gc, sizeof(int) * width);
		for (int j = 0; j < width; ++j) {
			array_dup[i][j] = array[i][j];
		}
	}
	return (array_dup);
}

void	print_board_1(int **board,  int height, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i != height)
	{
		j = 0;
		while (j != width)
		{
			dprintf(1, "%d", board[i][j]);
			j++;
		}
		dprintf(1, "\n");
		i++;
	}
	dprintf(1, "\n");

}
t_info_minimax minimax_recursive(t_board *board, int **board_content, t_player *player, int depth, t_list *gc) {
//	int score;
	t_pos *pos_piece = malloc_gc(&gc, sizeof(t_pos) * board->width);

	if (depth == 0) // NEED TO ADD END OF GAME(DRAW, WIN, LOSE)
	{
		t_info_minimax info;
		info.col = 100;
		info.score = 100;
//		info.col = pos_piece->col;
//		info.score = score_to_position(board, player, pos_piece);
//		print_board_1(board_content, board->height, board->width);
		return (info);
	}
//	if (player->starting_position) { // maximizingPlayer
		for (pos_piece->col = 0; pos_piece->col < board->width - 1; pos_piece->col++) {
//			score = INT_MIN;
			pos_piece->row = find_row_position(board_content, board->height, pos_piece->col);
			board_content[pos_piece->row][pos_piece->col] = player->starting_position;
			dprintf(1, "Col: %d, row: %d, for player: %d, depth: %d = \n", pos_piece->col, pos_piece->row, player->starting_position, depth);
//			print_board_1(board_content, board->height, board->width);
			if (player->starting_position == 1)
				player->starting_position = 2;
			else
				player->starting_position = 1;
			minimax_recursive(board, board_content, player, depth-1, gc);
//			info.score > score
//			if (pos_piece->row != -1) {
//				score = score_to_position(board, player, pos_piece);
//				if (max_score < score) {
//					max_score = score;
//					col = pos_piece->row;
//				}
//			}
		}
//	}
//	else { // minimizing player
//
//	}
	t_info_minimax info;
	info.col = 0;
	info.score = 0;
	return (info);
}

int minimax(t_board *board, t_player *player, t_list *gc){

	int line7[] = {0, 0, 0, 0, 0, 0, 0};
	int line6[] = {0, 0, 0, 0, 0, 0, 0};
	int line5[] = {0, 0, 0, 0, 0, 0, 0};
	int line4[] = {0, 0, 0, 0, 0, 0, 0};
	int line3[] = {1, 0, 0, 0, 0, 0, 0};
	int line2[] = {2, 0, 0, 0, 0, 0, 0};
	int line1[] = {2, 2, 0, 0, 0, 0, 0};

	board->content[0] = line1;
	board->content[1] = line2;
	board->content[2] = line3;
	board->content[3] = line4;
	board->content[4] = line5;
	board->content[5] = line6;
	board->content[6] = line7;



	//int **board_tmp = ft_array_int_dup(board->content, board->width, board->height, gc);
	//t_info_minimax  info = minimax_recursive(board,board_tmp, player, 2, gc);

	// TEST TO REMOVE 
	dprintf(1, "\n");
	print_board(board);
	t_pos *posix = malloc_gc(&gc, sizeof(t_pos));
	posix->row = 0;
	posix->col = 2;
	dprintf(1, "\n\nscore : %d\n", score_to_position(board, player, posix));

	return (1);
//	return (info.col);
}
