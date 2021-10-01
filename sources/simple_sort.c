#include "push_swap.h"

void	sort_2(t_ins_list **ins, t_list	**p)
{
	t_list	*a;

	a = *p;
	if (a->value > a->next->value)
		sa(ins, p);
}

void	sort_3(t_ins_list **ins, t_list	**p)
{
	t_list	*a;

	a = *p;
	if (a->value < a->next->value && a->value > a->next->next->value)
	{
		rra(ins, p);
		return ;
	}
	if (a->value < a->next->value && a->value < a->next->next->value)
	{
		ra(ins, p);
		sa(ins, p);
		rra(ins, p);
		return ;
	}
	if (a->value > a->next->value && a->value > a->next->next->value)
	{
		sa(ins, p);
		rra(ins, p);
		return ;
	}
	if (a->value > a->next->value && a->value < a->next->next->value)
	{
		sa(ins, p);
		return ;
	}
}

void	sort_4(t_ins_list **ins, t_list	**p, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	pb(ins, p, p_b);
	sort_3(ins, p);
	a = *p;
	b = *p_b;
	if (b->value > a->next->next->value)
	{
		pa(ins, p, p_b);
		pa(ins, p, p_b);
		ra(ins, p);
		return ;
	}
	if (b->value > a->next->value)
	{
		rra(ins, p);
		pa(ins, p, p_b);
		ra(ins, p);
		ra(ins, p);
		return ;
	}
	if (b->value > a->value)
	{
		pa(ins, p, p_b);
		sa(ins, p);
		return ;
	}
	if (b->value < a->value)
		pa(ins, p, p_b);
}

void	sort_5(t_ins_list **ins, t_list	**p, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	pb(ins, p, p_b);
	sort_4(ins, p, p_b);
	a = *p;
	b = *p_b;
	if (b->value > a->next->next->next->value)
	{
		pa(ins, p, p_b);
		ra(ins, p);
		return ;
	}
	if (b->value > a->next->next->value)
	{
		rra(ins, p);
		pa(ins, p, p_b);
		sa(ins, p);
		ra(ins, p);
		ra(ins, p);
		return ;
	}
	if (b->value > a->next->value)
	{
		ra(ins, p);
		pa(ins, p, p_b);
		sa(ins, p);
		rra(ins, p);
		return ;
	}
	if (b->value > a->value)
	{
		ra(ins, p);
		pa(ins, p, p_b);
		rra(ins, p);
		return ;
	}
	if (b->value < a->value)
		pa(ins, p, p_b);
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
