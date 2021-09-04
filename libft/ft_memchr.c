/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urichese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:44 by urichese          #+#    #+#             */
/*   Updated: 2021/04/22 19:53:46 by urichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	symbol;

	ptr = (unsigned char *)s;
	symbol = (unsigned char)c;
	while (n--)
	{
		if (*ptr == symbol)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
