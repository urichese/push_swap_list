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

t_list	*get_last(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	sort_5_2(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	a = *p_a;
	b = *p_b;
	if (b->value > a->next->value)
	{
		ra(ins, p_a);
		pa(ins, p_a, p_b);
		sa(ins, p_a);
		rra(ins, p_a);
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

void	sort_5(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	while ((*p_a)->order > get_last(*p_a)->order)
		ra(ins, p_a);
	pb(ins, p_a, p_b);
	sort_4(ins, p_a, p_b);
	a = *p_a;
	b = *p_b;
	if (b->value > a->next->next->next->value)
	{
		pa(ins, p_a, p_b);
		ra(ins, p_a);
		return ;
	}
	if (b->value > a->next->next->value)
	{
		rra(ins, p_a);
		pa(ins, p_a, p_b);
		ra(ins, p_a);
		ra(ins, p_a);
		return ;
	}
	sort_5_2(ins, p_a, p_b);
}

void	simple_sort(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	if (ft_lstsize(*p_a) == 2)
	{
		sort_2(ins, p_a);
		return ;
	}
	if (ft_lstsize(*p_a) == 3)
	{
		sort_3(ins, p_a);
		return ;
	}
	if (ft_lstsize(*p_a) == 4)
	{
		sort_4(ins, p_a, p_b);
		return ;
	}
	if (ft_lstsize(*p_a) == 5)
	{
		sort_5(ins, p_a, p_b);
		return ;
	}
}
