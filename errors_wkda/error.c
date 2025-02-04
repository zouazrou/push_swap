/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:13 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 11:39:30 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	inside_range_int(long nb)
{
	return (nb >= INT_MIN && nb <= INT_MAX);
}

int	check(char *av, t_bool sign)
{
	int		i;
	int		count;
	t_bool	non_zero;

	i = 0;
	count = 0;
	non_zero = FALSE;
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
	if (count > 11 || (sign == TRUE && non_zero == FALSE) || (sign == TRUE
			&& !av[0]))
		return (0);
	return (1337);
}

void	init_sign(t_bool *sign, char **av)
{
	*sign = TRUE;
	(*av)++;
}

void	extract_nb(char **nbrs, t_list **stack)
{
	int		i;
	long	nb;
	char	*av;
	t_bool	sign;

	if (!nbrs || !*nbrs || !**nbrs)
		(ft_free_array(nbrs), free_stacks(stack, NULL, TRUE));
	i = 0;
	while (nbrs[i])
	{
		av = nbrs[i];
		sign = FALSE;
		if ((*av == '-' || *av == '+'))
			init_sign(&sign, &av);
		if (!check(av, sign))
			(ft_free_array(nbrs), free_stacks(stack, NULL, TRUE));
		nb = ft_atoi(av - (sign == TRUE));
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
