#include "includes.h"

#define WINDOWS 4

static int calc_value_tab(const enum e_player tab[WINDOWS])
{
	int i;
	int number_of_op = 0;
	int number_of_player = 0;
	int number_of_none = 0;

	i = 0;
	while (i < WINDOWS)
	{
		if (tab[i] == HUMAN)
			number_of_op++;
		else if (tab[i] == AI)
			number_of_player++;
		else if (tab[i] == NONE)
			number_of_none++;
		i++;
	}
	if (number_of_player == 4)
		return (100);
	else if (number_of_player == 3 && number_of_none == 1 && number_of_op == 0)
		return (5);
	else if (number_of_player == 2 && number_of_none == 2 && number_of_op == 0)
		return (2);
	else if (number_of_op == 3 && number_of_none == 1 && number_of_player == 0)
		return (-4);
	return (0);
}

int	calc_board_value(t_size size, enum e_player tab[size.row][size.col])
{
	int	score;
	int x;
	int y;
	int i;

	score = 0;
	x = 0;
	// vertical
	while (x < size.col)
	{
		y = 0;
		while (y < size.row - 3)
		{
			score += calc_value_tab((enum e_player[WINDOWS]){tab[y][x], tab[y + 1][x], tab[y + 2][x], tab[y + 3][x]});
			y++;
		}
		x++;
	}
	// horizontal
	y = 0;
	while (y < size.row)
	{
		x = 0;
		while (x < size.col - 3)
		{
			score += calc_value_tab((enum e_player[WINDOWS]){tab[y][x], tab[y][x + 1], tab[y][x + 2], tab[y][x + 3]});
			x++;
		}
		y++;
	}

	// diagonal sw_ne
	x = -size.row;
	while (x < size.col)
	{
		i = 0;
		while (i < size.row)
		{
			if (!( x + i < 0 || x + i + 3 >= size.col || y + i < 0 || y + i + 3 >= size.row ))
				score += calc_value_tab((enum e_player[WINDOWS]){tab[i][x], tab[i + 1][x + 1 + i], tab[i + 2][x + 2 + i], tab[i + 3][x + 3 + i]});
			i++;
		}
		x++;
	}

	// diagonal nw_se
	x = 0;
	while (x < size.col + size.row)
	{
		i = 0;
		while (i < size.row - 3 )
		{
			if (!( x - i - 3 < 0 || x - i  >= size.col))
				score += calc_value_tab((enum e_player[WINDOWS]){tab[i][x - i], tab[i + 1][x - i - 1], tab[i + 2][x - i -  2], tab[i + 3][x - i - 3]});
			i++;
		}
		x++;
	}

	return (score);
}
