#include "../push_swap.h"

void	lstdel(t_ins_list *lst)
{
	if (lst)
		free(lst);
}
