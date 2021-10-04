#include "../push_swap.h"

void	lstadd_back(t_ins_list **lst, t_ins_list *new)
{
	t_ins_list	*buf;

	buf = *lst;
	if (buf)
	{
		while (buf != NULL && buf->next)
			buf = buf->next;
		buf->next = new;
	}
	else
		*lst = new;
	new->next = NULL;
}
