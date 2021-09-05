#include "push_swap.h"

void simple_sort(t_list	**p, t_list	**p_b)
{
	int		i;
	int		j;
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
