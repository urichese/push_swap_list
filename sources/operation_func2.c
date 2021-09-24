#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	rrb(t_list **b)
{
	rra(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rra(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*b_element;

	if (ft_lstsize(*b) == 0)
		return ;
	b_element = *b;
	*b = b_element->next;
	ft_lstadd_front(a, b_element);
}

void	pb(t_list **a, t_list **b)
{
	pa(b, a);
}

void	print_a(t_list *a)
{
	while (a)
	{
		ft_putstr_fd("a: ", 1);
		ft_putnbr_fd(a->value, 1);
		ft_putstr_fd("\n", 1);
		a = a->next;
	}
	ft_putstr_fd("\n", 1);
}

void	print_b(t_list *b) // delete
{
	while (b)
	{
		ft_putstr_fd("b: ", 1);
		ft_putnbr_fd(b->value, 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("\n", 1);
}
