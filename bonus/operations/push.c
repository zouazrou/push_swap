/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:40:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 17:52:59 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	push(t_list **stack, t_list *element)
{
	element->next = *stack;
	*stack = element;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = pop(stack_b);
	push(stack_a, node);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = pop(stack_a);
	push(stack_b, node);
	ft_putstr_fd("pb\n", 1);
}
