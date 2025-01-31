/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:13 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/23 13:27:27 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    free_stacks(t_list **_a, t_list **_b, BOOL err)
{
	if (_a)
		ft_lstclear(_a);
	if (_b)
		ft_lstclear(_b);
	if (err == TRUE)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	return ;
}

int	inside_range_int(long nb)
{
	return (nb >= INT_MIN && nb <= INT_MAX);
}
// ok
int		check(char *av)
{
	int		i;
	int		count;
	BOOL	non_zero;
	BOOL	sign;

	i = 0;
	count = 0;
	non_zero = FALSE;
	sign = FALSE;
	while (av[i])
	{
		if (!i && (av[i] == '-' || av[i] == '+'))
			(sign = TRUE),(i++);
		if (av[i] != '0')
			non_zero = TRUE;
		if (!ft_isdigit(av[i]))
			return (0);
		if (non_zero == TRUE)
			count++;
		i++;
	}
	if (count > 11 || (sign == TRUE && non_zero ==FALSE))
		return (0);
	return (1337);
}

void	extract_nb(char **nbrs, t_list **stack)
{
	int		i;
	long	nb;
	char	*av;

	if (!nbrs || !*nbrs || !**nbrs)
		(ft_free_array(nbrs), free_stacks(stack, NULL, TRUE));
	i = 0;
	while (nbrs[i])
	{
		av = nbrs[i];
		if(!check(av))
			(ft_free_array(nbrs), free_stacks(stack, NULL, TRUE));
		nb = ft_atoi(av);
		if (inside_range_int(nb))
			ft_lstadd_back(stack, ft_lstnew(nb));
		else
			(ft_free_array(nbrs), free_stacks(stack, NULL, TRUE));
		i++;
	}
	ft_free_array(nbrs);
}

void	stack_initialization(t_list **stack, int ac, char **av)
{
	int	i;
	char *arg;
	char **nbrs;

	i = 0;
	if (ac == 1)
		exit(0);
	*stack = NULL;
	while (i < ac - 1)
	{
		arg = av[i];
		if (!(*arg))
			free_stacks(stack, NULL, TRUE);
		nbrs = ft_split(arg, ' ');
		extract_nb(nbrs, stack);
		i++;
	}
	if (!(*stack) || isduplicate(*stack))
		free_stacks(stack, NULL, TRUE);
	
}
