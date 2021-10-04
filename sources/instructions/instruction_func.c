#include "../push_swap.h"

void free_ins(t_ins_list	*ins)
{
	t_ins_list	*buff;

	while (ins)
	{
		buff = ins;
		ins = ins->next;
		free(buff);
	}
}

void	del_past_ins(t_ins_list **ins)
{
	t_ins_list	*buf;

	buf = *ins;
	if (buf)
	{
		while (buf->next)
			buf = buf->next;
		lstdel(buf);
	}
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
	//ft_putnbr_fd(len, 1);
	//ft_putstr_fd("\n", 1);
	tmp = *ins;
	while (tmp)
	{
		ft_putstr_fd(tmp->name, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	free_ins(*ins);
	*ins = NULL;
}
