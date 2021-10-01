#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	sa(t_ins_list *ins, t_list **p)
{
	t_list	*x;
	t_list	*y;
	t_list	*a;

	a = *p;
	x = a;
	y = a->next;
	x->next = y->next;
	y->next = x;
	*p = y;
	put_ins(ins, "sa\0");
}

void	sb(t_ins_list *ins, t_list **a)
{
	sa(ins, a);
	put_ins(ins, "sb\0");
}

void	ra(t_ins_list *ins, t_list **p)
{
	t_list	*x;
	t_list	*a;

	a = *p;
	x = a;
	if (a == NULL || a->next == NULL)
		return ;
	*p = a->next;
	ft_lstadd_back(&a, x);
	put_ins(ins, "ra\0");
}

void	rb(t_ins_list *ins, t_list **b)
{
	ra(ins, b);
	put_ins(ins, "rb\0");
}

void	rra(t_ins_list *ins, t_list **a)
{
	t_list	*x;

	x = ft_lstlast(*a);
	if (*a == NULL || x == *a)
		return ;
	ft_lstadd_front(a, x);
	put_ins(ins, "rra\0");
}
