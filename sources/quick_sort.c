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

t_list	*get_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	get_max(t_list *lst)
{
	int i;
	if (!lst)
		return (0);
	i = lst->order;
	while (lst->next)
	{
		lst = lst->next;
		if (lst->order > i)
			i = lst->order;
	}
	return (i);
}

int	is_lstsorted(t_list	*a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->order > a->next->order)
			return (0);
		a = a->next;
	}
	return (1);
}

void put_from_a(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
				t_base_list	*base)
{
	int	i;

	i = (*p_a)->flag;
	while ((*p_a)->flag != (*p_a)->next->flag)
	{
		if ((*p_a)->order == base->next)
		{
			ra(ins, p_a);
			get_lstlast(*p_a)->flag = -1;
			base->next++;
		}
		else
			pb(ins, p_a, p_b);
		i--;
	}
	if (i == 2)
	{
		base->max = ft_lstsize(*p_a)/2;
		base->mid = (base->max + base->next) / 2;
		while ((*p_a)->flag != 1) // put b from 1 to mid
		{
			if ((*p_a)->order > base->mid)
				ra(ins, p_a);
			else
			{
				(*p_a)->new = 0;
				pb(ins, p_a, p_b);
			}
		}
		while (get_lstlast(*p_a)->flag != -1) // крутим назад
			rra(ins, p_a);
	}
	while (i == (*p_a)->flag && i != -1) // перекидывание кучи что были в b
	{
		if ((*p_a)->order == base->next)
		{
			ra(ins, p_a);
			get_lstlast(*p_a)->flag = -1;
			base->next++;
			continue ;
		}
		pb(ins, p_a, p_b);
	}
}

void	quick_sort_in_b(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
						t_base_list	*base)
{
	int	j;

	j = ft_lstsize(*p_b);
	while ((*p_b) != NULL && j > 0)
	{
		//if (j == 2 || j == 3)
		//	simple_sort_b(ins, p_b);
		if ((*p_b)->order == base->next)
		{
			pa(ins, p_a, p_b);
			ra(ins, p_a);
			get_lstlast(*p_a)->flag = -1;
			base->next++;
		}
		else if ((*p_b)->order > base->mid) //
			pa(ins, p_a, p_b);
		else
			rb(ins, p_b);
		j--;
	}
}

void	work_in_b(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
					  t_base_list	*base)
{
	while ((*p_b) != NULL || (*p_a)->new != 1)
	{
		while ((*p_b) != NULL && ft_lstsize(*p_b) != 0) // обработка внутри б
		{
			base->max = get_max(*p_b);
			base->mid = (base->max + base->next) / 2;
			quick_sort_in_b(ins, p_a, p_b, base);
		}
		if ((*p_a)->new != 1 && (*p_a)->flag != -1)
			put_from_a(ins, p_a, p_b, base);
		if (is_lstsorted(*p_a) == 1)
			break ;
	}
}
void	quick_sort_in(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
					  t_base_list	*base)
{
	work_in_b(ins, p_a, p_b, base);
	while ((*p_a)->order == base->next)
	{
		ra(ins, p_a);
		get_lstlast(*p_a)->flag = -1;
		base->next++;
	}
	base->max = ft_lstsize(*p_a);
	base->mid = (base->max + base->next) / 2;
	while ((*p_a)->flag != -1) // put b from 1 to mid
	{
		if ((*p_a)->order > base->mid)
			ra(ins, p_a);
		else
		{
			(*p_a)->new = 0;
			pb(ins, p_a, p_b);
		}
	}
	while (get_lstlast(*p_a)->flag != -1) // крутим назад
		rra(ins, p_a);

}

void	quick_sort(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	int	flag;
	t_base_list	*base;

	base = malloc(sizeof(t_base_list));
	base->next = 1;
	base->max = get_max(*p_a);
	base->mid = base->max / 2 + base->next;
	flag = 0;
	while ((*p_a)->flag == flag) // заполняем b с 1 до mid
	{
		//(*p_a)->max = base->max;
		if ((*p_a)->order > base->mid)
		{
			ra(ins, p_a);
		}
		else
		{
			(*p_a)->new = 0;
			pb(ins, p_a, p_b);
		}
	}
	while (is_lstsorted(*p_a) == 0 || (*p_b) != NULL) // todo
		quick_sort_in(ins, p_a, p_b, base);
	if (base)
		free(base);
}
