#include "libft.h"

static int	count(int n)
{
	int	c;

	c = 1;
	n = n / 10;
	while (n)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa(long n)
{
	char	*ptr;
	int		len;
	long	nb;

	len = count(n);
	nb = n;
	if (n < 0)
		len++;
	ptr = (char *) malloc(sizeof (char) * (len + 1));
	if (!ptr)
		return (0);
	if (n < 0)
	{
		ptr[0] = '-';
		nb = -nb;
	}
	ptr[len] = '\0';
	while (len--)
	{
		if (n < 0 && len == 0)
			break ;
		ptr[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ptr);
}
