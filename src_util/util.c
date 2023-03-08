
#include "includes.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int		res;
	int		neg;
	char	*current;

	res = 0;
	neg = 1;
	current = (char *)nptr;
	while (*current != '\0'
		   && ft_isspace((int)*current))
		current++;
	if (*current == '-' || *current == '+')
	{
		if (*current == '-')
			neg = -1;
		current++;
	}
	while (*current != '\0' && ft_isdigit((int)*current))
	{
		res *= 10;
		res += *current - 48;
		current++;
	}
	return (res * neg);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*int_str;
	size_t			index;

	index = 0;
	int_str = (unsigned char *)str;
	while (index < n)
	{
		int_str[index] = (unsigned char)c;
		index++;
	}
	return ((void *)str);
}

int min(int a, int b)
{
	return (a >= b ? b : a);
}

int max(int a, int b)
{
	return (a >= b ? a : b);
}