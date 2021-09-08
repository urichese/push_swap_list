#include "push_swap.h"

int is_lstsorted(t_list	*a)
{
	while (a)
	{
		if (a->order > a->next->order)
			return (0);
		a = a->next;
	}
	return (1);
}

void quick_sort(t_list	**p_a, t_list	**p_b)
{
	int i;
	int j;
	int	f;
	t_base_list *base;

	base = malloc(sizeof(t_base_list));
	base->next = 1;
	base->flag = 0;
	base->max = ft_lstsize(*p_a);
	base->mid = base->max / 2 + base->next;
	i = ft_lstsize(*p_a);
	while (is_lstsorted(*p_a) == 0)
	{
		while (i-- > 0)
		{
			if ((*p_a)->order >  base->mid)
				ra(p_a);
			else
				pb(p_a, p_b);
			f = (*p_a)->flag;
		}
		f = (*p_a)->flag;
		while (f != 0)
		{
			f = (*p_a)->flag;
			while (f == (*p_a)->flag)
			{
				pb(p_a, p_b);
				while (ft_lstsize(*p_b) != 0)
				{
					j = ft_lstsize(*p_b);
					while (j-- > 0)
					{
						base->max = base->mid;
						base->mid = (base->max - base->next) / 2 + base->next;
						base->flag++;
						if ((*p_b)->order > base->mid)
							rb(p_b);
						else
						{
							(*p_b)->flag = base->flag;
							pa(p_a, p_b);
							if ((*p_a)->order == base->next)
							{
								ra(p_a);
								base->next++;
							}
						}

					}
				}
			}
		}
		base->max = base->mid;
		base->mid = (base->max - base->next) / 2 + base->next;
	}
}