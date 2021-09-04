#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && (i + j) < (dstsize - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
