#include "includes.h"

char print_element[3] = {'O', 'H', 'A'};

void	print_board(t_size size, enum e_player tab[size.row][size.col])
{
	int		x;
	int 	y;

	y = size.row - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < size.col)
		{
			ft_putchar_fd(print_element[tab[y][x]], 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y--;
	}
	ft_putstr(1, "-------------------\n");
}