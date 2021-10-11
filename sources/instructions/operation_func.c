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

#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

void	sa(t_ins_list **ins, t_list **p)
{
	t_list	*x;
	t_list	*y;
	t_list	*a;

	a = *p;
	x = a;
	y = a->next;
	x->next = y->next;
	y->next = x;
	*p = y;
	put_ins(ins, "sa\0");
}

void	sb(t_ins_list **ins, t_list **p)
{
	t_list	*x;
	t_list	*y;
	t_list	*a;

	a = *p;
	x = a;
	y = a->next;
	x->next = y->next;
	y->next = x;
	*p = y;
	put_ins(ins, "sb\0");
}

void	ra(t_ins_list **ins, t_list **p)
{
	t_list	*x;
	t_list	*a;

	a = *p;
	x = a;
	if (a == NULL || a->next == NULL)
		return ;
	*p = a->next;
	x->flag++;
	ft_lstadd_back(&a, x);
	put_ins(ins, "ra\0");
}

void	rb(t_ins_list **ins, t_list **p)
{
	t_list	*x;
	t_list	*a;

	a = *p;
	x = a;
	if (a == NULL || a->next == NULL)
		return ;
	*p = a->next;
	x->flag++;
	ft_lstadd_back(&a, x);
	put_ins(ins, "rb\0");
}

void	rra(t_ins_list **ins, t_list **p)
{
	t_list	*x;

	if (!p || !(*p))
		return ;
	x = ft_lstlast(*p);
	if (*p == NULL || x == *p)
		return ;
	ft_lstadd_front(p, x);
	put_ins(ins, "rra\0");
}
