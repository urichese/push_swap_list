#include "libft.h"

t_ins_list	*lstnew(char *name)
{
	t_ins_list	*lst;

	lst = (t_list *) malloc(sizeof (t_ins_list));
	if (!lst)
		return (NULL);
	lst->name = name;
	lst->next = NULL;
	return (lst);
}
