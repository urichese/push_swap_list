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

static int	c_w(char const *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	if (!s[0])
		return (0);
	while (s[++i])
	{
		if (s[i] && s[i] == c && s[i + 1] != c)
			count++;
	}
	if (s[0] == c)
		count--;
	if (s[i - 1] == c)
		count--;
	return (count);
}

static char	**freemem(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	return (NULL);
}

static int	l_n_s(const char *s, char c)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (s[++i] && s[i] != c)
		len++;
	return (len);
}

static char	**ft_split1(char	**array, char const *s, char c)
{
	int		i;
	int		is_char;
	int		j;

	j = -1;
	i = -1;
	is_char = 1;
	while (s[++i])
	{
		if (!is_char && s[i] == c && s[i + 1] != c && s[i + 1])
			is_char = 1;
		if (is_char && s[i] != c)
		{
			array[++j] = ft_substr(s + i, 0, l_n_s(s + i, c));
			if (!array[j])
				return (freemem(array));
			is_char = 0;
		}
	}
	array[++j] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (c_w(s, c) + 1));
	if (!array)
		return (NULL);
	array = ft_split1(array, s, c);
	return (array);
}
