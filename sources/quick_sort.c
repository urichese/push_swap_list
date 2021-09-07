#include "push_swap.h"

void quick_sort(t_list	**p_a, t_list	**p_b)
{
	int		i;
	int		j;
	t_base_list	*base;

	base = malloc(sizeof (t_base_list));
	base->next = 1;
	base->flag = 0;
	base->max = ft_lstsize(*p_a);
	base->mid = base->max/2 + next;
}
