#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	size_t	little_len;
	size_t	j;
	size_t	i;
	size_t	t;

	b = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (b);
	i = 0;
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		if (b[i] == little[j])
		{
			t = i;
			while (b[t] == little[j] && little[j++] != '\0' && t++ < len)
				if (j == little_len)
					return (b + i);
		}
		i++;
	}
	return (NULL);
}
