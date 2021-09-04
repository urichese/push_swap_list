#include "push_swap.h"

char	**put_ins(char **ins, char *name)
{
	int		i;
	char	**temp;

	i = 0;
	while (ins[i] != NULL)
		i++;
	temp = ft_calloc(i+2, sizeof (char *));
	temp[i + 1] = NULL;
	ins[i] = name;
	while (i > -1)
	{
		temp[i] = ins[i];
		i--;
	}
	temp[i] = ins[i];
	//print_ins(temp);
	free(ins);
	ins = NULL;
	return (temp);
}

void	print_ins(char **ins)
{
	int		len;
	int 	i;

	len = 0;
	while (ins[len] != NULL)
		len++;
	i = 0;
	ft_putnbr_fd(len, 1);
	ft_putstr_fd("\n", 1);
	while (i < len)
	{
		ft_putstr_fd(ins[i++], 1);
		ft_putstr_fd("\n", 1);
	}
	//free(ins);
}
