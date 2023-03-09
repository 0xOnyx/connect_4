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


static size_t	max_len(int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_fill_tab(int nb, char *tab, size_t len)
{
	size_t	i;

	i = len;
	if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
		tab++;
		i--;
	}
	while (i-- > 0)
	{
		tab[i] = '0' + (nb % 10);
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = max_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_fill_tab(n, res, len);
	res[len] = '\0';
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}