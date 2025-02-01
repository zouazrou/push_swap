/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:38:19 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/01 11:25:21 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_initialization(&stack_a, ac, av + 1);
	stack_b = NULL;
	size_a = ft_lstsize(stack_a);
	if (size_a == 2 && !is_sorted(stack_a))
		return (sa(&stack_a), 0);
	else if (size_a == 3)
		tree_nmbrs(&stack_a);
	else if (size_a > 3)
		sort_stack(&stack_a, &stack_b);
	return (free_stacks(&stack_a, &stack_b, FALSE), 0);
}
