/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urichese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2021/04/22 19:53:25 by urichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_list(t_list	*list)
{
	t_list	*buff;

	while (list)
	{
		buff = list;
		list = list->next;
		if (buff)
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
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_sorted(a, argc - 1) == 1)
	{
		free(a);
		a = NULL;
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
	free(a);
	//print_list(list_a);
	if (list_a)
		free_list(list_a);
	return (0);
}
