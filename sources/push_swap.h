/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urichese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2021/04/22 19:53:25 by urichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_base_list
{
	int	next;
	int	mid;
	int	max;
}				t_base_list;

typedef struct s_ins_list
{
	char				*name;
	struct s_ins_list	*next;
}				t_ins_list;

void		sa(t_ins_list **ins, t_list **a);
void		sb(t_ins_list **ins, t_list **b);
void		ra(t_ins_list **ins, t_list **a);
void		rb(t_ins_list **ins, t_list **b);
void		rra(t_ins_list **ins, t_list **a);
void		rrb(t_ins_list **ins, t_list **b);
void		rrr(t_ins_list **ins, t_list **a, t_list **b);
void		pa(t_ins_list **ins, t_list **a, t_list **b);
void		pb(t_ins_list **ins, t_list **a, t_list **b);

int			is_lstsorted(t_list	*a);
int			*check(int argc, char **argv);
int			ft_isnumber(const char *str);
int			*quick_sort_array(int *a, int low, int high);
int			is_sorted(int *a, int len);
int			get_order(int *a, int len, int c);
void		ft_swap(int *a, int *b);
int			*copy(int *a, int len);
t_list		*get_list(int *a, int len);

void		simple_sort(t_ins_list **ins, t_list	**a, t_list	**b);
void		quick_sort(t_ins_list **ins, t_list	**p_a, t_list	**p_b);

int			lstsize(t_ins_list *lst);
void		lstadd_back(t_ins_list **lst, t_ins_list *new);
t_ins_list	*lstnew(char *name);
void		lstdel(t_ins_list *lst);

void		put_ins(t_ins_list **ins, char *name);
void		print_ins(t_ins_list **ins);
void		del_past_ins(t_ins_list **ins);

void	sort_4(t_ins_list **ins, t_list	**p_a, t_list	**p_b);
void	sort_4_2(t_ins_list **ins, t_list	**p_a, t_list	**p_b);
void	sort_3(t_ins_list **ins, t_list	**p_a);
void	sort_3_2(t_ins_list **ins, t_list	**p_a);
void	sort_2(t_ins_list **ins, t_list	**p_a);

#endif
