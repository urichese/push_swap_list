#include "push_swap.h"
void sort_3(t_list	**p)
{
	t_list	*a;

	a = *p;
	if (a->value < a->next->value && a->value > a->next->next->value)
		rra(a);
	if (a->value < a->next->value && a->value < a->next->next->value)
	{
		ra(p);
		sa(p);
		rra(p);
	}
	if (a->value > a->next->value && a->value > a->next->next->value)
	{
		sa(p);
		rra(p);
	}
}

void sort_4(t_list	**p, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	pb(p, p_b);
	sort_3(p);
	a = *p;
	b = *p_b;
	if (b->value > b->next->value)
		sb(p_b);
	if (b->value > a->next->next->value )
	{
		pa(p, p_b);
		pa(p, p_b);
		ra(p);
	}
	if (b->value > a->next->value )
	{
		rra(p);
		pa(p, p_b);
		ra(p);
		ra(p);
	}
	if (b->value < a->next->value )
	{
		pa(p, p_b);
		sa(p);
	}
	if (b->value < a->value )
		pa(p, p_b);
}

void sort_5(t_list	**p, t_list	**p_b)
{
	t_list	*a;
	t_list	*b;

	while (ft_lstsize(*p) != 3)
		pb(p, p_b);
	sort_4(p, p_b);
	a = *p;
	b = *p_b;
	if (b->value > a->next->next->next->value)
	{
		pa(p, p_b);
		ra(p);
	}
	if (b->value > a->next->next->value)
	{
		rra(p);
		pa(p, p_b);
		sa(p);
		ra(p);
		ra(p);
	}
	if (b->value > a->next->next->value)
	{
		rra(p);
		pa(p, p_b);
		sa(p);
		ra(p);
		ra(p);
	}
	if (b->value > a->next->value)
	{
		ra(p);
		pa(p, p_b);
		sa(p);
		rra(p);
	}
	if (b->value > a->value)
	{
		ra(p);
		pa(p, p_b);
		rra(p);
	}
	if (b->value < a->value)
		pa(p, p_b);
}
void simple_sort(t_list	**p_a, t_list	**p_b)
{
	int		i;
	int		j;
	t_list	*a;
	t_list	*b;

	if (ft_lstsize(*p_a) == 3)
		sort_3(p_a);
	if (ft_lstsize(*p_a) == 4)
		sort_4(p_a, p_b);
	if (ft_lstsize(*p_a) == 4)
		sort_5(p_a, p_b);
}
