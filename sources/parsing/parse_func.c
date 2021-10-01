#include "../push_swap.h"

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
