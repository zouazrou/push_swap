/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anther_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:38:02 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 20:58:15 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	just_do_a(t_list **_a, t_list **_b, t_list *node)
{
	t_list	*target;

	target = node->target;
	while ((*_b)->cheapest == FALSE && node->above == TRUE)
		rb(_b);
	while ((*_b)->cheapest == FALSE && node->above == FALSE)
		rrb(_b);
	while ((*_a)->cheapest == FALSE && target->above == TRUE)
		ra(_a);
	while ((*_a)->cheapest == FALSE && target->above == FALSE)
		rra(_a);
}

void	just_do_b(t_list **_a, t_list **_b, t_list *node)
{
	t_list	*target;

	target = node->target;
	while ((*_a)->cheapest == FALSE && node->above == TRUE)
		ra(_a);
	while ((*_a)->cheapest == FALSE && node->above == FALSE)
		rra(_a);
	while ((*_b)->cheapest == FALSE && target->above == TRUE)
		rb(_b);
	while ((*_b)->cheapest == FALSE && target->above == FALSE)
		rrb(_b);
}

void	do_rrr(t_list **_a, t_list **_b)
{
	while ((*_a)->cheapest == FALSE && (*_b)->cheapest == FALSE)
		rrr(_a, _b);
	while ((*_a)->cheapest == FALSE)
		rra(_a);
	while ((*_b)->cheapest == FALSE)
		rrb(_b);
}

void	do_rr(t_list **_a, t_list **_b)
{
	while ((*_a)->cheapest == FALSE && (*_b)->cheapest == FALSE)
		rr(_a, _b);
	while ((*_a)->cheapest == FALSE)
		ra(_a);
	while ((*_b)->cheapest == FALSE)
		rb(_b);
}

void	do_op_to_top(t_list **_a, t_list **_b, t_list *node, char flag)
{
	t_list	*target;

	target = node->target;
	if (node->above == TRUE && target->above == TRUE)
		do_rr(_a, _b);
	else if (node->above == FALSE && target->above == FALSE)
		do_rrr(_a, _b);
	else if (flag == 'b')
		just_do_b(_a, _b, node);
	else if (flag == 'a')
		just_do_a(_a, _b, node);
}
