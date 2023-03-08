#include "includes.h"

int	main(int argc, char **argv)
{
	t_size	size;
	time_t	time_value;

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
	enum e_player	tab[size.row][size.col];
	int 		 	current_pos[size.col];

	if (time(&time_value) < 0)
	{
		ft_putstr(1, "[failed]\tto get time\n");
		return (3);
	}
	srand((unsigned int)time_value);
	ft_memset((void *)tab, 0, sizeof(enum e_player) * size.row * size.col);
	ft_memset((void *)current_pos, 0, sizeof(int) * size.col);
	play_game(size, tab, current_pos, (rand() % 2) ?  AI : HUMAN);
	return (0);
}

