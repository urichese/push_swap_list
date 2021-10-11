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
	if (a->value > a->next->value && a->value > a->next->next->value &&
		a->next->value < a->next->next->value)
	{
		rb(ins, p_a);
		return ;
	}
	if (a->value > a->next->value && a->value > a->next->next->value &&
		a->next->value > a->next->next->value)
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

void	simple_sort_b(t_ins_list **ins, t_list	**p_a)
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
}
