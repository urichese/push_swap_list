#include "push_swap.h"

void quick_sort(t_list	**p_a, t_list	**p_b)
{
	int		i;
	int		j;
	t_list	*a;
	t_list	*b;

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
