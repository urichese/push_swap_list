#include "libft.h"

long	ft_atoi(const char *str)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
	}
	return ((result * sign));
}
