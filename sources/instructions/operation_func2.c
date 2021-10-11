#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

void	rrb(t_ins_list **ins, t_list **p)
{
	t_list	*x;

	if (!p || !(*p))
		return ;
	x = ft_lstlast(*p);
	if (*p == NULL || x == *p)
		return ;
	ft_lstadd_front(p, x);
	put_ins(ins, "rrb\0");
}

void	rrr(t_ins_list **ins, t_list **a, t_list **b)
{
	rra(ins, a);
	del_past_ins(ins);
	rra(ins, b);
	del_past_ins(ins);
	put_ins(ins, "rrr\0");
}

void	pa(t_ins_list **ins, t_list **a, t_list **b)
{
	t_list	*b_element;

	if (ft_lstsize(*b) == 0)
		return ;
	b_element = *b;
	*b = b_element->next;
	b_element->flag++;
	ft_lstadd_front(a, b_element);
	put_ins(ins, "pa\0");
}

void	pb(t_ins_list **ins, t_list **a, t_list **b)
{
	t_list	*a_element;

	if (ft_lstsize(*a) == 0)
		return ;
	a_element = *a;
	a_element->flag++;
	*a = a_element->next;
	ft_lstadd_front(b, a_element);
	put_ins(ins, "pb\0");
}
