#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int	*copy(int *a, int len)
{
	int	i;
	int	*a_sorted;

	a_sorted = malloc(sizeof (int) * len);
	i = 0;
	while (i < len)
	{
		a_sorted[i] = a[i];
		i++;
	}
	return (a_sorted);
}

int	partition(int *a, int low, int high)
{
	int	pivot;
	int	i;

	pivot = low - 1;
	i = low;
	while (i < high)
	{
		if (a[i] < a[high])
		{
			pivot++;
			ft_swap(&a[i], &a[pivot]);
		}
		i++;
	}
	pivot++;
	ft_swap(&a[pivot], &a[high]);
	return (pivot);
}

int	*quick_sort_array(int *a, int low, int high)
{
	int	p;

	if (low < high)
	{
		p = partition(a, low, high);
		quick_sort_array(a, low, p - 1);
		quick_sort_array(a, p + 1, high);
	}
	return (a);
}

int	get_order(int *a, int len, int c)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] == c)
			return (i + 1);
		i++;
	}
	return (i);
}

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
