#include "push_swap.h"

int is_lstsorted(t_list	*a)
{
	while (a != NULL && a->next != NULL)
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
	while (i-- > 0)
	{
		if ((*p_a)->order >  base->mid)
			ra(p_a);
		else
			pb(p_a, p_b);
	}
	while (is_lstsorted(*p_a) == 0)
	{
		i = ft_lstsize(*p_a) - base->next + 1;
		while (i-- > 0)
		{
			if ((*p_a)->order <=  base->mid ) // заполняем б
				pb(p_a, p_b);
			else
				ra(p_a);
		}
		i = ft_lstsize(*p_a) - base->next + 1;
		while (i-- > 0)
		{
			if ((*p_b)->order != base->next)
				rrr(p_a, p_b);
			else
				rra(p_a);
		}
		f = 1;
		while (f != 0)
		{
			while (ft_lstsize(*p_b) != 0)
			{
				base->max = base->mid;
				base->mid = (base->max - base->next) / 2 + base->next;
				base->flag++;
				j = ft_lstsize(*p_b);
				while (j-- > 0)
				{
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
				if (base->max == base->next)
					break ;
			}
			f = (*p_a)->flag;
			while (f == (*p_a)->flag  && f != 0)
			{
				pb(p_a, p_b);
			}
		}
		base->max = base->mid;
		base->mid = (base->max - base->next) / 2 + base->next;
		while ((*p_a)->order ==  base->next ) // если след элемент то вниз
		{
			ra(p_a);
			base->next++;
		}
	}
}