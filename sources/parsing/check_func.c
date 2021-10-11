#include "../push_swap.h"

int	check_error(int argc, char **argv)
{
	int		i;
	long	c;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_isnumber(argv[i + 1]) == 0)
			return (0);
		c = ft_atoi(argv[i + 1]);
		if (c < -214748364 - 1 || c > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(int argc, int *a)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (a[i] == a[j++])
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	*check(int argc, char **argv)
{
	int		i;
	long	c;
	int		*a;

	if (check_error(argc, argv) == 0)
		return (NULL);
	a = malloc(sizeof (*a) * (argc - 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		c = ft_atoi(argv[i + 1]);
		a[i] = (int) c;
		i++;
	}
	if (check_dup(argc, a) == 0)
	{
		free(a);
		return (NULL);
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
