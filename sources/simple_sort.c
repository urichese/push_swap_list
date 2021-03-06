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

#include "push_swap.h"

void	sort_2(t_ins_list **ins, t_list	**p_a)
{
	t_list	*a;

	a = *p_a;
	if (a->value > a->next->value)
		sa(ins, p_a);
}

void	sort_3_2(t_ins_list **ins, t_list	**p_a)
{
	t_list	*a;

	a = *p_a;
	if (a->value > a->next->value && a->value > a->next->next->value
		&& a->next->value > a->next->next->value)
	{
		sa(ins, p_a);
		rra(ins, p_a);
		return ;
	}
	if (a->value > a->next->value && a->value < a->next->next->value)
	{
		sa(ins, p_a);
		return ;
	}
}

void	sort_3(t_ins_list **ins, t_list	**p_a)
{
	t_list	*a;

	a = *p_a;
	if (is_lstsorted(a) == 1)
		return ;
	if (a->value < a->next->value && a->value > a->next->next->value)
	{
		rra(ins, p_a);
		return ;
	}
	if (a->value < a->next->value && a->value < a->next->next->value)
	{
		ra(ins, p_a);
		sa(ins, p_a);
		rra(ins, p_a);
		return ;
	}
	if (a->value > a->next->value && a->value > a->next->next->value
		&& a->next->value < a->next->next->value)
	{
		ra(ins, p_a);
		return ;
	}
	sort_3_2(ins, p_a);
}

void	sort_4_2(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	a = *p_a;
	b = *p_b;
	if (b->value > a->next->value)
	{
		rra(ins, p_a);
		pa(ins, p_a, p_b);
		ra(ins, p_a);
		ra(ins, p_a);
		return ;
	}
	if (b->value > a->value)
	{
		pa(ins, p_a, p_b);
		sa(ins, p_a);
		return ;
	}
	if (b->value < a->value)
		pa(ins, p_a, p_b);
}

void	sort_4(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	if (is_lstsorted(*p_a) == 1)
		return ;
	pb(ins, p_a, p_b);
	sort_3(ins, p_a);
	a = *p_a;
	b = *p_b;
	if (b->value > a->next->next->value)
	{
		pa(ins, p_a, p_b);
		ra(ins, p_a);
		return ;
	}
	sort_4_2(ins, p_a, p_b);
}
