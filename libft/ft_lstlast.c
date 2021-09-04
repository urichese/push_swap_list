#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

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
