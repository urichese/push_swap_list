#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	buf = *lst;
	if (buf)
	{
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
	else
		*lst = new;
	new->next = NULL;
}
