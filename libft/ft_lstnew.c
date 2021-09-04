#include "libft.h"

t_list	*ft_lstnew(int value, int order)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof (t_list));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->order = order;
	lst->flag = 0;
	lst->next = NULL;
	return (lst);
}
