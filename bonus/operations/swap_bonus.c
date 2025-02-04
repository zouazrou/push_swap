/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:42:11 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:22:36 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!(stack) || !(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list **_a, t_list **_b)
{
	(void)_b;
	swap(_a);
}

void	sb(t_list **_a, t_list **_b)
{
	(void)_a;
	swap(_b);
}

void	ss(t_list **_a, t_list **_b)
{
	swap(_a);
	swap(_b);
}
