#ifndef CONNECT_4_UTILS_H
# define CONNECT_4_UTILS_H

# include "includes.h"

enum e_player
{
	NONE,
	HUMAN,
	AI,
};

enum e_minmax
{
	MAXIMIZER,
	MINIMIZER,
};

typedef struct s_size
{
	int col;
	int row;
} t_size;

typedef struct s_pos
{
	int x;
	int y;
} t_pos;

void	ft_putchar_fd(char c, int fd);
int		ft_putstr(int fd, char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_memset(void *str, int c, size_t n);
int 	min(int a, int b);
int 	max(int a, int b);

#endif
