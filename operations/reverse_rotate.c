/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:44:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 20:54:29 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*s_to_last;
	t_list	*last;

	s_to_last = ft_lstsecondtolast(*stack);
	if (!s_to_last)
		return ;
	last = s_to_last->next;
	s_to_last->next = NULL;
	push(stack, last);
}

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
