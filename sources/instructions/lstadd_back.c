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

#include "../push_swap.h"

void	lstadd_back(t_ins_list **lst, t_ins_list *new)
{
	t_ins_list	*buf;

	buf = *lst;
	if (buf)
	{
		while (buf != NULL && buf->next)
			buf = buf->next;
		buf->next = new;
	}
	else
		*lst = new;
	new->next = NULL;
}
