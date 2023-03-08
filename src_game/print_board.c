#include "includes.h"

char *print_element[3] = {"\033[90m_\033[0m", "\033[33mH\033[0m", "\033[31mA\033[0m"};

void	print_board(t_size size, enum e_player tab[size.row][size.col])
{
	int		x;
	int 	y;
	char	*tmp;

	if (size.row > 10)
		ft_putchar_fd('\t', 1);
	else
		ft_putstr(1, "  ");
	y = 0;
	while (y < size.col)
	{
		tmp = ft_itoa(y);
		ft_putstr(1, tmp);
		ft_putchar_fd(' ', 1);
		free(tmp);
		y++;
	}
	ft_putchar_fd('\n', 1);
	y = size.row - 1;
	while (y >= 0)
	{
		x = 0;
		tmp = ft_itoa(y);
		ft_putstr(1, tmp);

		if (size.row > 10)
			ft_putchar_fd('\t', 1);
		else
			ft_putchar_fd(' ', 1);

		while (x < size.col)
		{
			ft_putstr(1, print_element[tab[y][x]]);
			ft_putchar_fd(' ', 1);
			x++;
		}
		if (size.row > 10)
			ft_putchar_fd('\t', 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putstr(1, tmp);
		free(tmp);
		ft_putchar_fd('\n', 1);
		y--;
	}
	if (size.row > 10)
		ft_putchar_fd('\t', 1);
	else
		ft_putstr(1, "  ");
	y = 0;
	while (y < size.col)
	{
		tmp = ft_itoa(y);
		ft_putstr(1, tmp);
		ft_putchar_fd(' ', 1);
		free(tmp);
		y++;
	}
	ft_putstr(1, "\n<------------------->\n");
}