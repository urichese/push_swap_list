#include "push_swap.h"

void simple_sort(t_list	**p, t_list	**p_b)
{
	int		i;
	int		j;
	t_list	*a;
	t_list	*b;

	while (ft_lstsize(*p) != 3)
		pb(p, p_b);
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
	a = *p;
	b = *p_b;
	if (b->value > b->next->value)
		sb(p_b);
	if (b->value > a->next->next->value )
	{
		pa(p, p_b);
		pa(p, p_b);
		ra(p);
		ra(p); // 5 elen
	}
	if (b->value > a->next->value )
	{
		rra(p);
		pa(p, p_b);
		ra(p);
		ra(p);
	}
	if (b->value > a->next->value && b->next->value > a->next->next->value)
	{
		rra(p);
		pa(p, p_b);
		ra(p);
		ra(p);
		pa(p, p_b);
		ra(p);
	}
 
}
