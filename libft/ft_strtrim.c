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

int	in_set(char const *s, char c)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		l;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	i = 0;
	while (in_set(set, s1[i++]))
		start++;
	l = ft_strlen(s1);
	end = 0;
	while (in_set(set, s1[--l]))
		end++;
	if (start == end && start == (int)ft_strlen(s1))
		end = 0;
	l = ft_strlen(s1) - start - end;
	s2 = (char *) malloc(sizeof(char) * (l + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + start, l + 1);
	return (s2);
}
