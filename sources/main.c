#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*a;
	t_list	*list_a;
	t_list	*list_b;
	t_ins_list *ins;

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
		//printf("sorted"); // redo
		return (0);
	}
	list_a = get_list(a, argc - 1);
	//printf("in:\n");
	//print_list(list_a);
	if (ft_lstsize(list_a) > 5)
		quick_sort(&ins, &list_a, &list_b);
	else
		simple_sort(&ins, &list_a, &list_b);
	//printf("----------\n");
	//printf("sorted:\n");
	//print_list(list_a);
	//printf("----------\n");
	//printf("b:\n");
	//print_list(list_b);
	print_ins(ins);
	return (0);
}
