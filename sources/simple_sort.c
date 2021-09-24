#include "push_swap.h"

void	sort_2(t_list	**p)
{
	t_list	*a;

	a = *p;
	if (a->value > a->next->value)
		sa(p);
}

void	sort_3(t_list	**p)
{
	t_list	*a;

	a = *p;
	if (a->value < a->next->value && a->value > a->next->next->value)
	{
		rra(p);
		return ;
	}
	if (a->value < a->next->value && a->value < a->next->next->value)
	{
		ra(p);
		sa(p);
		rra(p);
		return ;
	}
	if (a->value > a->next->value && a->value > a->next->next->value)
	{
		sa(p);
		rra(p);
		return ;
	}
	if (a->value > a->next->value && a->value < a->next->next->value)
	{
		sa(p);
		return ;
	}
}

void	sort_4(t_list	**p, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	pb(p, p_b);
	sort_3(p);
	a = *p;
	b = *p_b;
	if (b->value > a->next->next->value)
	{
		pa(p, p_b);
		pa(p, p_b);
		ra(p);
		return ;
	}
	if (b->value > a->next->value)
	{
		rra(p);
		pa(p, p_b);
		ra(p);
		ra(p);
		return ;
	}
	if (b->value > a->value)
	{
		pa(p, p_b);
		sa(p);
		return ;
	}
	if (b->value < a->value)
		pa(p, p_b);
}

void	sort_5(t_list	**p, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	pb(p, p_b);
	sort_4(p, p_b);
	a = *p;
	b = *p_b;
	if (b->value > a->next->next->next->value)
	{
		pa(p, p_b);
		ra(p);
		return ;
	}
	if (b->value > a->next->next->value)
	{
		rra(p);
		pa(p, p_b);
		sa(p);
		ra(p);
		ra(p);
		return ;
	}
	if (b->value > a->next->value)
	{
		ra(p);
		pa(p, p_b);
		sa(p);
		rra(p);
		return ;
	}
	if (b->value > a->value)
	{
		ra(p);
		pa(p, p_b);
		rra(p);
		return ;
	}
	if (b->value < a->value)
		pa(p, p_b);
}

void	simple_sort(t_list	**p_a, t_list	**p_b)
{
	if (ft_lstsize(*p_a) == 2)
	{
		sort_2(p_a);
		return ;
	}
	if (ft_lstsize(*p_a) == 3)
	{
		sort_3(p_a);
		return ;
	}
	if (ft_lstsize(*p_a) == 4)
	{
		sort_4(p_a, p_b);
		return ;
	}
	if (ft_lstsize(*p_a) == 5)
	{
		sort_5(p_a, p_b);
		return ;
	}
}
