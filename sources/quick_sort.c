#include "push_swap.h"

int	is_lstsorted(t_list	*a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->order > a->next->order)
			return (0);
		a = a->next;
	}
	return (1);
}

void	quick_sort_in_b(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
						t_base_list	*base)
{
	int	j;

	j = ft_lstsize(*p_b);
	while (j-- > 0) // обработка самого б
	{
		if ((*p_b) && (*p_b)->order == base->next) //если то что
			// перекинули next то перекидываем вниз
		{
			pa(ins, p_a, p_b);
			ra(ins, p_a);
			base->next++;
			continue ;
		}
		else if ((*p_b)->order < base->mid) // если меньше mid то перекидываем
		// вниз
			rb(ins, p_b);
		else
		{
			(*p_b)->flag = base->flag;
			pa(ins, p_a, p_b);
		}
	}
}

int	quick_sort_in_a(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
					   t_base_list	*base)
{
	int	i;

	i = (*p_a)->flag;
	while (i == (*p_a)->flag && i != 0) // перекидывание кучи что были в b
	{
		if ((*p_a)->order == base->next)
		{
			ra(ins, p_a);
			base->next++;
			continue ;
		}
		pb(ins, p_a, p_b);
	}
	return (i);
}

void	quick_sort_in(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
					  t_base_list	*base)
{
	int	i;

	i = 1;
	while (i != 0) // цикл закидывания обратно тех массивов что уже были в б
	{
		while (ft_lstsize(*p_b) != 0) // обработка внутри б пока не пустой
			// в б
		{
			base->max = base->mid;
			base->mid = (base->max - base->next) / 2 + base->next;
			base->flag++;
			quick_sort_in_b(ins, p_a, p_b, base);
		}
		i = quick_sort_in_a(ins, p_a, p_b, base);
	}
	while ((*p_a)->order == base->next) // если след элемент то вниз
	{
		ra(ins, p_a);
		base->next++;
	}
}

void	quick_sort_part(t_ins_list **ins, t_list	**p_a, t_list	**p_b,
						t_base_list	*base)
{
	int			i;
	int			len;

	len = ft_lstsize(*p_a);
	i = ft_lstsize(*p_a) - base->next + 1;
	while (i-- > 0) // заполняем б с 1 до mid
	{
		if ((*p_a)->order <= base->mid)
			pb(ins, p_a, p_b);
		else
			ra(ins, p_a);
	}
	i = ft_lstsize(*p_a) - base->next + 1;
	while (i-- > 0) // крутим назад
	{
		if ((*p_b) != NULL && (*p_b)->order != base->next)
			rrr(ins, p_a, p_b);
		else
			rra(ins, p_a);
	}
	quick_sort_in(ins, p_a, p_b, base);
	base->max = len;
	base->mid = (base->max - base->next) / 2 + base->next;
}

void	quick_sort(t_ins_list **ins, t_list	**p_a, t_list	**p_b)
{
	int			len;
	t_base_list	*base;

	len = ft_lstsize(*p_a);
	base = malloc(sizeof(t_base_list));
	base->next = 1;
	base->flag = 0;
	base->max = len;
	base->mid = base->max / 2 + base->next;
	while (is_lstsorted(*p_a) == 0)
	{
		quick_sort_part(ins, p_a, p_b, base);
	}
}
