#include "rush_02.h"


// JE DOIS PRENDRE EN COMPTE LE FAIT QUE CE N'EST PAS QUE UN PUISSANCE 4
int calculate_score_with_line_of_piece(int count_line_of_piece) {
	if (count_line_of_piece == 2)
		return (2);
	else if (count_line_of_piece == 3)
		return (5);
	else if (count_line_of_piece == 4)
		return (100);
	return (0);
}

int score_horizontal(int **board_content, int board_width, int numero_player, t_pos *pos_piece)
{
	int count = 0;
	// ON THE LEFT SIDE
	for (int i = 1; pos_piece->col - i != -1 && board_content[pos_piece->row][pos_piece->col - i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// ON THE RIGHT SIDE
	for (int i = 1; pos_piece->col + i != board_width && board_content[pos_piece->row][pos_piece->col + i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// WE GIVE OUR PIECES PLUS ALL PIECES ON THE LEFT AND RIGHT SIDE
	return (calculate_score_with_line_of_piece(count + 1));
}

int score_vertical(int **board_content, int numero_player, t_pos *pos_piece)
{
	int count = 0;
	// ON THE BOTTOM SIDE
	for (int i = 1; pos_piece->row - i != -1 && board_content[pos_piece->row - i][pos_piece->col] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// WE GIVE OUR PIECES PLUS ALL PIECES ON THE TOP AND BOTTOM SIDE
	return (calculate_score_with_line_of_piece(count + 1));
}

int score_diagonal_left(int **board_content, int board_width, int board_height, int numero_player, t_pos *pos_piece)
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
	return (calculate_score_with_line_of_piece(count + 1));
}

int score_diagonal_right(int **board_content, int board_width, int board_height, int numero_player, t_pos *pos_piece)
{
	int count = 0;
	// ON THE TOP RIGHT SIDE
	for (int i = 1; pos_piece->col + i != board_width && pos_piece->row + 1 != board_height && board_content[pos_piece->row + i][pos_piece->col + i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// ON THE BOTTOM LEFT SIDE
	for (int i = 1; pos_piece->col - i != -1 && pos_piece->row - i != -1 && board_content[pos_piece->row - i][pos_piece->col - i] == numero_player; i++) {
		count++; // while we have piece count++;
	}
	// WE GIVE OUR PIECES PLUS ALL PIECES ON THE TOP AND BOTTOM SIDE
	return (calculate_score_with_line_of_piece(count + 1));
}
