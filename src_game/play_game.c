#include "includes.h"

int	play_game(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col], enum e_player first_player)
{
	enum e_player 	winner;
	t_pos			pos;
	enum e_player	current_player;
	unsigned int 	number_of_plays;

	current_player = first_player;
	number_of_plays = 0;
	do
	{
		print_board(size, tab);
		if (current_player == HUMAN)
			pos = play_human(size, tab, current_pos);
		else if (current_player == AI)
			pos = play_ai(size, tab, current_pos);
		tab[pos.y][pos.x] = current_player;
		current_player = current_player == HUMAN ? AI: HUMAN;
		number_of_plays++;
	}while ( !(winner = has_won(size, tab, pos)) && number_of_plays < (unsigned int)(size.row * size.col));
	print_board(size, tab);
	if (winner)
	{
		ft_putstr(1, "[WINNER]\t");
		winner == HUMAN ? ft_putstr(1, "HUMAN") : ft_putstr(1, "AI");
		ft_putchar_fd('\n', 1);
	}
	else
		ft_putstr(1, "[DRAW]\n");
	return (0);
}