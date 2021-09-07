#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
