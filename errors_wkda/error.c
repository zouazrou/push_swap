/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:13 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 22:48:15 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_list **_a, t_list **_b, t_bool err)
{
	if (_a)
		ft_lstclear(_a);
	if (_b)
		ft_lstclear(_b);
	if (err == TRUE)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return ;
}

int	inside_range_int(long nb)
{
	return (nb >= INT_MIN && nb <= INT_MAX);
}

int	check(char *av)
{
	int		i;
	int		count;
	t_bool	non_zero;
	t_bool	sign;

	i = 0;
	count = 0;
	non_zero = FALSE;
	sign = FALSE;
	if ((av[i] == '-' || av[i] == '+'))
	{
		i++;
		sign = TRUE;
	}
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		if (av[i] != '0')
			non_zero = TRUE;
		if (non_zero == TRUE)
			count++;
		i++;
	}
	if (count > 11 || (sign == TRUE && non_zero == FALSE) || (sign == TRUE && !av[1]))
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
		if (!check(av))
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
	int		i;
	char	*arg;
	char	**nbrs;

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
