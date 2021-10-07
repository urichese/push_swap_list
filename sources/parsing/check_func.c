#include "../push_swap.h"

int 	*check(int argc, char **argv)
{
	int		i;
	int		j;
	long	c;
	int		*a;

	a = malloc(sizeof (*a) * (argc - 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (ft_isnumber(argv[i + 1]) == 0)
		{
			free(a);
			return (NULL);
		}
		c = ft_atoi(argv[i + 1]);
		if (c < -214748364 - 1 || a[i] > 2147483647)
		{
			free(a);
			return (NULL);
		}
		a[i] = (int) c;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
			if (a[i] == a[j++])
			{
				free(a);
				return (NULL);
			}
		i++;
	}
	return (a);
}

int	ft_isnumber(const char *str)
{
	size_t			i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
