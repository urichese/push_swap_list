#include "../push_swap.h"

void	put_ins(t_ins_list **ins, char *name)
{
	t_ins_list *new;

	new = lstnew(name);
	lstadd_back(ins, new);
}
t_ins_list	**zip_ins(t_ins_list **ins)
{
	int	f;
	t_ins_list *tmp;

	f = 1;
	tmp = *ins;
	while (f == 1)
	{
		f = 0;
		while (1)
		{
			if ((tmp->name == "sa\0" && tmp->next->name == "sb\0") ||
					(tmp->name == "sb\0" && tmp->next->name == "sa\0"))
			{
				tmp->name == "ss\0";
				tmp->next = tmp->next->next;
				lstdel(tmp->next);
				f = 1;
			}
			if (tmp->name == "ra\0" && tmp->next->name == "rb\0" ||
				tmp->name == "rb\0" && tmp->next->name == "ra\0")
			{
				tmp->name == "rr\0";
				tmp->next = tmp->next->next;
				lstdel(tmp->next);
				f = 1;
			}
			if (tmp->name == "rra\0" && tmp->next->name == "rrb\0" ||
				tmp->name == "rrb\0" && tmp->next->name == "rra\0")
			{
				tmp->name == "rrr\0";
				tmp->next = tmp->next->next;
				lstdel(tmp->next);
				f = 1;
			}
			tmp = tmp->next;
			if (tmp == NULL || tmp->next == NULL)
				break ;
		}
	}
	return ins;
}
void	print_ins(t_ins_list **ins)
{
	int		len;
	t_ins_list *tmp;

	zip_ins(ins);
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
