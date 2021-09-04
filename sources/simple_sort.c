#include "push_swap.h"

void simple_sort(t_list	*a)
{
	int		i;
	int		j;
	if (a->value < a->next->value && a->value > a->next->next->value)
		rra(a);
	if (a->value < a->next->value && a->value < a->next->next->value)
	{
		ra(a);
		sa(a);
		rra(a);
	}
}
