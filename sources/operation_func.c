#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	sa(t_list **p)
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
}

void	sb(t_list **a)
{
	sa(a);
}

void	ra(t_list **p)
{
	t_list	*x;
	t_list	*a;

	a = *p;
	x = a;
	*p = a->next;
	ft_lstadd_back(&a, x);
}

void	rb(t_list **b)
{
	ra(b);
}

void	rra(t_list **a)
{
	t_list	*x;

	x = ft_lstlast(*a);
	ft_lstadd_front(a, x);
}
