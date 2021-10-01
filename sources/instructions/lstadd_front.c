#include "libft.h"

void	lstadd_front(t_ins_list **lst, t_ins_list *new)
{
	new->next = *lst;
	*lst = new;
}
