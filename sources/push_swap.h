#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_base_list
{
	int				next;
	int 			mid;
	int 			max;
	int 			flag;
}				t_base_list;

void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
int		*check(int argc, char **argv);
int		ft_isnumber(const char *str);
char	**put_ins(char **ins, char *name);
void	print_ins(char **ins);
int 	*quick_sort_array(int *a, int low, int high);
int 	is_sorted(int *a, int len);
int 	get_order(int *a, int len, int c);
void 	ft_swap(int *a, int *b);
int 	*copy(int *a, int len);
t_list	*get_list(int *a, int len);
void	print_list(t_list	*a);
void	simple_sort(t_list	**a, t_list	**b);
void 	quick_sort(t_list	**p_a, t_list	**p_b);
//void	libft/ft_putstr_fd(char *s, int fd);

#endif
