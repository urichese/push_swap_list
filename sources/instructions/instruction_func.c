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

#include "../push_swap.h"

void	free_ins(t_ins_list	*ins)
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
	t_ins_list	*new;

	new = lstnew(name);
	lstadd_back(ins, new);
}

void	print_ins(t_ins_list **ins)
{
	t_ins_list	*tmp;

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
