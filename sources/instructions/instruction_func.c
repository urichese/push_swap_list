#include "../push_swap.h"

void	del_first_ins(t_ins_list **ins)
{
	t_ins_list *tmp;

	tmp = *ins;
	(*ins)= (*ins)->next;
	lstdel(tmp);
}

void	put_ins(t_ins_list **ins, char *name)
{
	t_ins_list *new;

	new = lstnew(name);
	lstadd_back(ins, new);
}

void	print_ins(t_ins_list **ins)
{
	int		len;
	t_ins_list *tmp;

	//zip_ins(ins);
	len = lstsize(*ins);
	ft_putnbr_fd(len, 1);
	ft_putstr_fd("\n", 1);
	tmp = *ins;
	while (tmp)
	{
		ft_putstr_fd(tmp->name, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	//free(ins);
}
