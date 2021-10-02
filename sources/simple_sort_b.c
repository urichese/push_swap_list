#include "push_swap.h"

void	sort_2b(t_ins_list **ins, t_list	**p_a)
{
	t_list	*a;

	a = *p_a;
	if (a->value > a->next->value)
		sb(ins, p_a);
}

void	sort_3b(t_ins_list **ins, t_list	**p_a)
{
	t_list	*a;

	a = *p_a;
	if (is_lstsorted(a) == 1)
		return ;
	if (a->value < a->next->value && a->value > a->next->next->value)
	{
		rrb(ins, p_a);
		return ;
	}
	if (a->value < a->next->value && a->value < a->next->next->value)
	{
		rb(ins, p_a);
		sb(ins, p_a);
		rrb(ins, p_a);
		return ;
	}
	if (a->value > a->next->value && a->value > a->next->next->value)
	{
		sb(ins, p_a);
		rrb(ins, p_a);
		return ;
	}
	if (a->value > a->next->value && a->value < a->next->next->value)
	{
		sb(ins, p_a);
		return ;
	}
}

void	sort_4b(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	if (is_lstsorted(*p_a) == 1)
		return ;
	pb(ins, p_a, p_b);
	sort_3b(ins, p_a);
	a = *p_a;
	b = *p_b;
	if (b->value > a->next->next->value)
	{
		pb_vb(ins, p_a, p_b);
		rb(ins, p_a);
		return ;
	}
	if (b->value > a->next->value)
	{
		rrb(ins, p_a);
		pb_vb(ins, p_a, p_b);
		rb(ins, p_a);
		rb(ins, p_a);
		return ;
	}
	if (b->value > a->value)
	{
		pb_vb(ins, p_a, p_b);
		sb(ins, p_a);
		return ;
	}
	if (b->value < a->value)
		pb_vb(ins, p_a, p_b);
}

void	sort_5b(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	if (is_lstsorted(*p_a) == 1)
		return ;
	pb(ins, p_a, p_b);
	sort_4b(ins, p_a, p_b);
	a = *p_a;
	b = *p_b;
	if (b->value > a->next->next->next->value)
	{
		pb_vb(ins, p_a, p_b);
		rb(ins, p_a);
		return ;
	}
	if (b->value > a->next->next->value)
	{
		rrb(ins, p_a);
		pb_vb(ins, p_a, p_b);
		rb(ins, p_a);
		rb(ins, p_a);
		return ;
	}
	if (b->value > a->next->value)
	{
		rb(ins, p_a);
		pb_vb(ins, p_a, p_b);
		sb(ins, p_a);
		rrb(ins, p_a);
		return ;
	}
	if (b->value > a->value)
	{
		pb_vb(ins, p_a, p_b);
		sb(ins, p_a);
		return ;
	}
	if (b->value < a->value)
		pb_vb(ins, p_a, p_b);
}

void	simple_sort_b(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	if (is_lstsorted(*p_a) == 1)
		return ;
	if (ft_lstsize(*p_a) == 2)
	{
		sort_2b(ins, p_a);
		return ;
	}
	if (ft_lstsize(*p_a) == 3)
	{
		sort_3b(ins, p_a);
		return ;
	}
	if (ft_lstsize(*p_a) == 4)
	{
		sort_4b(ins, p_a, p_b);
		return ;
	}
	if (ft_lstsize(*p_a) == 5)
	{
		sort_5b(ins, p_a, p_b);
		return ;
	}
}
