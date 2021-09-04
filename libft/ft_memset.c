/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urichese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:55:29 by urichese          #+#    #+#             */
/*   Updated: 2021/04/22 19:55:31 by urichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	copy;

	result = (unsigned char *)b;
	i = 0;
	copy = (unsigned char)c;
	while (i < len)
	{
		result[i] = copy;
		i++;
	}
	return (b);
}
