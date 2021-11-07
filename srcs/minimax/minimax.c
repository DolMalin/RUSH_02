#include "rush_02.h"

int score_to_position(t_board *board, int **board_content, int player, t_pos *pos_piece){

	int score;
	score = score_horizontal(board_content, board->width, player, pos_piece);
	score += score_vertical(board_content, player, pos_piece);
	score += score_diagonal_left(board_content, board->width, board->height, player, pos_piece);
	score += score_diagonal_right(board_content, board->width, board->height, player, pos_piece);
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

	i = height - 1;
	while (i != -1)
	{
		j = 0;
		while (j != width)
		{
			dprintf(1, "%d", board[i][j]);
			j++;
		}
		dprintf(1, "\n");
		i--;
	}
	dprintf(1, "\n");

}
t_info_minimax minimax_recursive(t_board *board, int **board_content, int maximizing_player, int depth, t_list *gc, int column) {
	t_info_minimax new_info;
	t_info_minimax info;

	if (depth == 0) // NEED TO ADD END OF GAME(DRAW, WIN, LOSE)
	{
		t_pos *pos = malloc_gc(&gc, sizeof(t_pos));
		pos->col = column;
		pos->row = find_row_position(board_content, board->height, column);
		info.col = column;
		info.score = score_to_position(board, board_content, maximizing_player + 1, pos);
		dprintf(1, "col: %d, row: %d, score: %d, player: %d\n", column, pos->row, info.score, maximizing_player + 1);
		print_board_1(board_content, board->height, board->width);
		return (info);
	}
	if (maximizing_player) {
		info.col = 0;
		info.score = INT_MIN;
		for (int col = 0; col < board->width; col++) {
			int **board_tmp = ft_array_int_dup(board_content, board->width, board->height, gc);
			int row = find_row_position(board_tmp, board->height, col);
			dprintf(1, "MAXIMIZING PLAYER : row: %d, col: %d\n", row, col);

			board_tmp[row][col] = maximizing_player + 1;
			new_info = minimax_recursive(board, board_tmp, 0, depth - 1, gc, col);
			if (new_info.score > info.score) {
				info.score = new_info.score;
				info.col = new_info.col;
			}
		}
		return info;
	}
	else { // Minimizing player
		info.col = 0;
		info.score = INT_MAX;
		for (int col = 0; col < board->width; col++) {
			int **board_tmp = ft_array_int_dup(board->content, board->width, board->height, gc);
			int row = find_row_position(board_tmp, board->height, col);
			board_tmp[row][col] = maximizing_player + 1;
			dprintf(1, "MINIMIZING PLAYER : row: %d, col: %d\n", row, col);
			new_info = minimax_recursive(board, board_tmp, 1, depth - 1, gc, col);
			if (new_info.score < info.score) {
				info.score = new_info.score;
				info.col = new_info.col;
			}
		}
		return info;
	}
}

int minimax(t_board *board, t_player *player, t_list *gc){

	int line7[] = {0, 0, 0, 0, 0, 0, 0};
	int line6[] = {0, 0, 0, 0, 0, 0, 0};
	int line5[] = {0, 0, 0, 0, 0, 0, 0};
	int line4[] = {0, 0, 0, 0, 0, 0, 0};
	int line3[] = {0, 0, 0, 0, 0, 0, 0};
	int line2[] = {0, 0, 0, 0, 0, 0, 0};
	int line1[] = {0, 0, 0, 0, 0, 0, 0};

	board->content[0] = line1;
	board->content[1] = line2;
	board->content[2] = line3;
	board->content[3] = line4;
	board->content[4] = line5;
	board->content[5] = line6;
	board->content[6] = line7;
	(void)player;
	(void)gc;
//	t_pos *pos_piece = malloc_gc(&gc, sizeof(t_pos) * board->width);
//	dprintf(1, "%d\n", score_to_position(board,player, pos_piece));
//	if(player->starting_position == )
	t_info_minimax  info = minimax_recursive(board,board->content, player->starting_position - 1, 2, gc, 0);
	dprintf(1, "score: %d, col: %d\n", info.score, info.col);
//	return (pos_piece->col);
	return (info.col);
}
