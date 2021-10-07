#include "push_swap.h"

void free_list(t_list	*list)
{
	t_list	*buff;

	while (list)
	{
		buff = list;
		list = list->next;
		free(buff);
	}
}

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
		return (0);
	}
	//ins = malloc(sizeof(t_ins_list)); //todo refactor
	ins = NULL;
	list_b = NULL;
	list_a = NULL;
	list_a = get_list(a, argc - 1);
	if (ft_lstsize(list_a) > 5)
		quick_sort(&ins, &list_a, &list_b);
	else
		simple_sort(&ins, &list_a, &list_b);
	//ft_putstr_fd("wwwwww", 1);
	//print_list(list_a);
	print_ins(&ins);
	//print_list(list_a);
	//fflush(stdout); //todo remove
	free_list(list_a);
	free_list(list_b);
	free(a);
	free(ins);
	return (0);
}
