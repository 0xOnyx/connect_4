#include "includes.h"

int	main(int argc, char **argv)
{
	t_size size;

	if (argc != 3)
	{
		ft_putstr(1, "[failed]\tusage => ./connect4 [row] [col]\n");
		return (1);
	}

	if ((size.row = ft_atoi(argv[1])) < 6
	|| (size.col = ft_atoi(argv[2])) < 7)
	{
		ft_putstr(1, "[error]\tto small row or col\n");
		return (2);
	}
    //	                 Y         X
	enum e_player tab[size.row][size.col];
	ft_memset((void *)tab, 0, sizeof(enum e_player) * size.row * size.col);

	play_game(size, tab, HUMAN);
	printf("value of 0 0  -> %d\n", tab[0][0]);
	return (0);
}

