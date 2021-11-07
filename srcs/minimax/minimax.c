#include "rush_02.h"


int score_to_position(t_board *board, t_player *player, t_pos *pos_piece){

	int score;
	score = score_horizontal(board->content, board->width, player->starting_position, pos_piece);
	score += score_vertical(board->content, player->starting_position, pos_piece);
	score += score_diagonal_left(board->content, board->width, board->height, player->starting_position, pos_piece);
	score += score_diagonal_right(board->content, board->width, board->height, player->starting_position, pos_piece);
	return (score);
}


int find_row_position(int **board_content, int board_height, int col) {

	if (board_content[board_height - 1][col] != 0)
		return -1;
	int pos = 0;
	for (pos = 0 ; pos != board_height && board_content[pos][col] != 0; pos++);
	return pos;
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

	t_pos *pos_piece = malloc_gc(&gc, sizeof(t_pos) * board->width);
	pos_piece->col = 0;
	int score = 0;
	int col = 0;
	int max_score = 0;

	for (pos_piece->col = 0; pos_piece->col < board->width; ++pos_piece->col) {
		pos_piece->row = find_row_position(board->content, board->height, pos_piece->col);
		if (pos_piece->row != -1) {
			score = score_to_position(board, player, pos_piece);
			if (max_score < score) {
				max_score = score;
				col = pos_piece->row;
			}
		}
	}
	return (col);
}
