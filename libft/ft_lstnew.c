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

t_list	*ft_lstnew(int value, int order)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof (t_list));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->order = order;
	lst->flag = 0;
	lst->new = 1;
	lst->next = NULL;
	return (lst);
}
