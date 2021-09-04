/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urichese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2021/04/22 19:53:25 by urichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	t;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	t = (unsigned char )c;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (n--)
	{
		d[i] = s[i];
		if (s[i] == t)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
