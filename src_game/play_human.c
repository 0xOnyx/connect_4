#include "includes.h"

static int    get_col(t_size size, enum e_player tab[size.row][size.col])
{
	char    str[200];
	int     column;

	while (1)
	{
		ft_putstr(1, "select >");
		if (read(STDIN_FILENO, str, 200) <= 1)
		{
			ft_putstr(1, "Not a valid column\n");
			continue;
		}
		column = ft_atoi(str);
		if (column >= 0 && column < size.col)
		{
			if (tab[size.row - 1][column] != 0)
				ft_putstr(1, "Column is already full\n");
			else
				return (column);
		}
		else
			ft_putstr(1, "Not a valid column\n");
	}
}

t_pos play_human(t_size size, enum e_player tab[size.row][size.col], int current_pos[size.col])
{
	t_pos	pos;

	pos.x = get_col(size, tab);
	pos.y = current_pos[pos.x];
	current_pos[pos.x]++;
	return (pos);
}