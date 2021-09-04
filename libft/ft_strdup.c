#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
