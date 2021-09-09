#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	//char	**ins;
	t_list	*list_a;
	t_list	*list_b;

	if (argc - 1 == 0)
		return (0);
	a = check(argc, argv);
	if (a == NULL)
	{
		ft_putstr_fd("Error", 2);
		return (0);
	}
	if (is_sorted(a, argc - 1) == 1)
	{
		printf("sorted"); // redu
		return (0);
	}
	list_a = get_list(a, argc - 1);
	printf("in:\n");
	print_list(list_a);
	if(ft_lstsize(list_a) > 5)
		quick_sort(&list_a, &list_b);
	else
		simple_sort(&list_a, &list_b);
	printf("----------\n");
	printf("sorted:\n");
	print_list(list_a);
	printf("----------\n");
	printf("b:\n");
	print_list(list_b);
	return (0);
}
