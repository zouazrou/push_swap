/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:40:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:26:13 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	push(t_list **stack, t_list *element)
{
	if (!element)
		return ;
	element->next = *stack;
	*stack = element;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = pop(stack_b);
	if (!node)
		return ;
	push(stack_a, node);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = pop(stack_a);
	if (!node)
		return ;
	push(stack_b, node);
}
