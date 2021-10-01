#include "../push_swap.h"

t_ins_list	*lstlast(t_ins_list *lst)
{
	t_ins_list	*tmp;

	if (!lst)
		return (NULL);
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (lst);
}
