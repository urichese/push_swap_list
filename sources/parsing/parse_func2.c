#include "../push_swap.h"

t_list	*get_list(int *a, int len)
{
	int		i;
	t_list	*list;
	t_list	*tmp;
	int		*a_sorted;

	a_sorted = copy(a, len);
	a_sorted = quick_sort_array(a_sorted, 0, len - 1);
	i = 0;
	tmp = ft_lstnew(a[i], get_order(a_sorted, len, a[i]));
	list = tmp;
	i = 0;
	while (++i < len)
	{
		tmp->next = ft_lstnew(a[i], get_order(a_sorted, len, a[i]));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	free(a_sorted);
	return (list);
}

void	print_list(t_list	*a)
{
	while (a)
	{
		printf("a->value = %d, a->flag = %d, a->order = %d \n", a->value,
			   a->flag, a->order);
		a = a->next;
	}
}
