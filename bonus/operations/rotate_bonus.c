/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:42:08 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:26:13 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	rotate(t_list **stack)
{
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstlast(*stack)->next = first;
}

void	ra(t_list **_a, t_list **_b)
{
	(void)_b;
	rotate(_a);
}

void	rb(t_list **_a, t_list **_b)
{
	(void)_a;
	rotate(_b);
}

void	rr(t_list **_a, t_list **_b)
{
	rotate(_a);
	rotate(_b);
}
