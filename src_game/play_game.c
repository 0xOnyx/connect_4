#include "includes.h"

int	play_game(t_size size, enum e_player tab[size.row][size.col], enum e_player first_player)
{
	t_pos			pos;
	enum e_player	current_player;

	current_player = first_player;
	do
	{
		print_board(size, tab);
		if (current_player == HUMAN)
		{
			pos = play_human(size, tab);
		}
		else if (current_player == AI)
		{
			//pos = play_ai(); TODO: implement this
			pos = play_human(size, tab);
		}
		tab[pos.y][pos.x] = current_player;
		current_player = current_player == HUMAN ? AI: HUMAN;
	}while (!has_won(size, tab, pos));
	return (0);
}