#include "../push_swap.h"

void free_ins(t_ins_list	*ins)
{
	t_ins_list	*buff;

	while (ins)
	{
		buff = ins;
		ins = ins->next;
		if (buff != NULL)
		{
			free(buff);
			buff = NULL;
		}
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
		buf = NULL;
	}
}

void	put_ins(t_ins_list **ins, char *name)
{
	t_ins_list *new;

	new = lstnew(name);
	lstadd_back(ins, new);
}
void	zip_ins(t_ins_list **ins)
{
	t_ins_list *tmp;
	t_ins_list *del;
	int i;

	tmp = *ins;
	i = 1;
	while (i == 1)
	{
		i = 0;
		while (tmp && tmp->next)
		{
			if ((ft_strcmp(tmp->name, "ra") == 0 &&
			ft_strcmp(tmp->next->name, "rb") == 0 )
			|| (ft_strcmp(tmp->name, "rb") == 0
			&& ft_strcmp(tmp->next->name, "ra")== 0) )
			{
				tmp->name = "rr";
				del = tmp->next;
				tmp->next = tmp->next->next;
				free (del);
				del = NULL;
				i = 1;
			}
			if ((ft_strcmp(tmp->name, "rra") == 0
			&& ft_strcmp(tmp->next->name, "rrb") == 0)
			|| (ft_strcmp(tmp->name, "rrb") == 0
			&& ft_strcmp(tmp->next->name, "rra") == 0))
			{
				tmp->name = "rrr";
				del = tmp->next;
				if (del)
				{
					tmp->next = tmp->next->next;
					free(del);
					del = NULL;
				}
				i = 1;
			}
			if ((ft_strcmp(tmp->name, "sa") == 0
			&& ft_strcmp(tmp->next->name,"sb") == 0)
				|| (ft_strcmp(tmp->name, "sb") == 0 &&
				ft_strcmp (tmp->next->name,"sa") == 0))
			{
				tmp->name = "ss";
				del = tmp->next;
				tmp->next = tmp->next->next;
				free (del);
				del = NULL;
				i = 1;
			}
			tmp = tmp->next;
		}
	}
}
void	print_ins(t_ins_list **ins)
{
	int		len;
	t_ins_list *tmp;

	zip_ins(ins);
	len = lstsize(*ins);
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
