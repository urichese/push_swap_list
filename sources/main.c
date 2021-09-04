#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	char	**ins;
	t_list	*list_a;
	int i = 0;

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
		printf("sorted"); //
		return (0);
	}
	i = 0;
	list_a = get_list(a, argc - 1);
	print_list(list_a);
	simple_sort(list_a);
	print_list(list_a);
	printf("assss");
	return (0);
}
