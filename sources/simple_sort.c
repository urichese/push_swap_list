#include "push_swap.h"

void	sort_2(t_ins_list **ins, t_list	**p_a)
{
	t_list	*a;

	a = *p_a;
	if (a->value > a->next->value)
		sa(ins, p_a);
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
	if (a->value > a->next->value && a->value > a->next->next->value &&
			a->next->value < a->next->next->value)
	{
		ra(ins, p_a);
		return ;
	}
	if (a->value > a->next->value && a->value > a->next->next->value &&
									 a->next->value > a->next->next->value)
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
t_list	*get_last(t_list *a)
{
	t_list *tmp;


	tmp = a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return tmp;
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
