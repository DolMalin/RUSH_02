#include "rush_02.h"

int score_to_position(t_board *board, int **board_copy, t_player *player, t_pos *pos_piece) {
	int score;
	score = score_horizontal(board, board_copy, player->starting_position, pos_piece);
	score += score_vertical(board_copy, board->win_len, player->starting_position, pos_piece);
	score += score_diagonal_left(board_copy, board->width, board->height, board->win_len, player->starting_position,
								 pos_piece);
	score += score_diagonal_right(board, board_copy, board->width, board->height, board->win_len,
								  player->starting_position, pos_piece);
	score += score_middle(board->width, pos_piece);
	return (score);
}


t_info_minimax score_to_all_position(t_board *board, t_player *player, int **board_copy){

	int score;
	t_info_minimax info;

	info.score = -INT_MIN;
	t_pos *pos = malloc(sizeof(t_pos));
	for (int i = 0; i < board->width; ++i) {
		pos->col = i;
		pos->row = find_row_position(board_copy, board->height, pos->col);
		if (pos->row != -1) {
			score = score_to_position(board, board_copy, player, pos);
			if (score > info.score) {
				info.score = score;
				info.col = i;
			}
		}
	}
	free(pos);
	return (info);
}
// JE DOIS PRENDRE EN COMPTE LE FAIT QUE CE N'EST PAS QUE UN PUISSANCE 4
int calculate_score_with_line_of_piece(int count_line_of_piece, int	win_len) {
	if (win_len == 3)
	{
		if (count_line_of_piece == 2)
			return (2);
		else if (count_line_of_piece == 3)
			return (10000);
		return (0);
	}
	else if (win_len == 4)
	{
		if (count_line_of_piece == 2)
			return (2);
		else if (count_line_of_piece == 3)
			return (5);
		else if (count_line_of_piece == 4)
			return (10000);
		return (0);
	}
	else if (win_len == 5)
	{
		if (count_line_of_piece == 2)
			return (2);
		else if (count_line_of_piece == 3)
			return (5);
		else if (count_line_of_piece == 4)
			return (15);
		else if (count_line_of_piece == 5)
			return (10000);
		return (0);
	}
	return (0);
}


int	blank_horizontal(int **board_content, int board_width, int numero_player, t_pos *pos_piece)
{
	int	count = 0;	

	// AVOID BUFFER OVERFLOW
	if (pos_piece->col - 2 < 0 || pos_piece->col + 2 > board_width - 1)
		return (0);
	// ON THE LEFT SIDE
	if (board_content[pos_piece->row][pos_piece->col - 2] == numero_player && board_content[pos_piece->row][pos_piece->col - 1] == 0)
		count += 1;
	// ON THE RIGHT SIDE
	if (board_content[pos_piece->row][pos_piece->col + 2] == numero_player && board_content[pos_piece->row][pos_piece->col + 1] == 0)
		count += 1;
	return (count);
}

int	blank_diagonal(int **board_content, int board_width, int board_height, int numero_player, t_pos *pos_piece)
{
	int count = 0;

	// AVOID BUFFER OVERFLOW
	if (pos_piece->col - 2 < 0 || pos_piece->col + 2 > board_width - 1 || pos_piece->row + 2 > board_height - 1 || pos_piece->row - 2 < 0)
		return (0);
	// ON THE TOP LEFT SIDE
	if (board_content[pos_piece->row + 2][pos_piece->col - 2] == numero_player && board_content[pos_piece->row + 1][pos_piece->col - 1] == 0)
		count += 1;
	// ON THE TOP RIGHT SIDE
	if (board_content[pos_piece->row + 2][pos_piece->col + 2] == numero_player && board_content[pos_piece->row + 1][pos_piece->col + 1] == 0)
		count += 1;
	// ON THE BOTTOM LEFT SIDE
	return (count);
}

int score_horizontal(t_board *board, int **board_content, int numero_player, t_pos *pos_piece)
{
	int count = 0;
	// ON THE LEFT SIDE
	for (int i = 1; pos_piece->col - i != -1 && board_content[pos_piece->row][pos_piece->col - i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// ON THE RIGHT SIDE
	for (int i = 1; pos_piece->col + i != board->width && board_content[pos_piece->row][pos_piece->col + i] == numero_player; i++) {
		count++; // while we have piece count++;
	}

	// BLANK BETWIN PIECES ON THE LEFT SIDE
	// WE GIVE OUR PIECES PLUS ALL PIECES ON THE LEFT AND RIGHT SIDE
	return (calculate_score_with_line_of_piece(count + 1, board->win_len) + blank_horizontal(board_content, board->width, numero_player, pos_piece));
}

int score_vertical(int **board_content, int win_len, int numero_player, t_pos *pos_piece)
{
	int count = 0;
	// ON THE BOTTOM SIDE
	for (int i = 1; pos_piece->row - i != -1 && board_content[pos_piece->row - i][pos_piece->col] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// WE GIVE OUR PIECES PLUS ALL PIECES ON THE TOP AND BOTTOM SIDE
	return (calculate_score_with_line_of_piece(count + 1, win_len));
}

int score_diagonal_left(int **board_content, int board_width, int board_height, int win_len, int numero_player, t_pos *pos_piece)
{
	int count = 0;
	// ON THE TOP LEFT SIDE
	for (int i = 1; pos_piece->col - i != -1 && pos_piece->row + i != board_height && board_content[pos_piece->row + i][pos_piece->col - i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// ON THE BOTTOM RIGHT SIDE
	for (int i = 1; pos_piece->col + i != board_width && pos_piece->row - i != -1 && board_content[pos_piece->row - i][pos_piece->col + i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// WE GIVE OUR PIECES PLUS ALL PIECES ON THE TOP AND BOTTOM SIDE
	return (calculate_score_with_line_of_piece(count + 1, win_len) + blank_diagonal(board_content, board_width, board_height, numero_player, pos_piece));
}

int score_diagonal_right(t_board *board, int **board_content, int board_width, int board_height, int win_len, int numero_player, t_pos *pos_piece)
{
	int count = 0;
	// ON THE TOP RIGHT SIDE
	(void)board;
//	dprintf(1, "col: %d, row:%d\n", pos_piece->col, pos_piece->row);
//	print_board(board);
	for (int i = 1; pos_piece->col + i != board_width && pos_piece->row + i != board_height && board_content[pos_piece->row + i][pos_piece->col + i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// ON THE BOTTOM LEFT SIDE
	for (int i = 1; pos_piece->col - i != -1 && pos_piece->row - i != -1 && board_content[pos_piece->row - i][pos_piece->col - i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// WE GIVE OUR PIECES PLUS ALL PIECES ON THE TOP AND BOTTOM SIDE
	return (calculate_score_with_line_of_piece(count + 1, win_len));
}

int	score_middle(int board_width, t_pos *pos_piece)
{
	if (board_width % 2 == 1)
	{
		if (pos_piece->col == (board_width / 2))
			return (4);
	}
	else
	{
		if (pos_piece->col == (board_width / 2) || pos_piece->col == (board_width / 2) - 1)
			return (4);
	}
	return (0);
}
