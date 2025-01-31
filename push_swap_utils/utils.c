/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:38:06 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 20:58:44 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

int	ft_abs(int n)
{
	return (n * ((n > 0) - (n < 0)));
}

void	indexing(t_list *stack, int size)
{
	int	index;
	int	average;

	index = 0;
	average = size / 2;
	while (stack)
	{
		stack->index = index;
		stack->cheapest = FALSE;
		stack->above = (index <= average);
		stack->cost = ((stack->above == TRUE) * index)
			+ ((stack->above == FALSE) * (size - index));
		index++;
		stack = stack->next;
	}
	return ;
}

int	min_moves(t_list *node)
{
	int		moves;
	t_list	*target;

	target = node->target;
	if (node->above == TRUE && target->above == TRUE)
		return (ft_max(node->cost, target->cost));
	if (node->above == FALSE && target->above == FALSE)
		return (ft_max(node->cost, target->cost));
	return (node->cost + target->cost);
}
