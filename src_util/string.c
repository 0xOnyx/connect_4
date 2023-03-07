#include "includes.h"


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_putstr(int fd, char *s)
{
	size_t	res;

	res = 0;
	while (*s)
		res += write(fd, s++, 1);
	return (res);
}
