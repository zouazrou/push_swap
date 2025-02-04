/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:44:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:26:13 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*s_to_last;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	s_to_last = ft_lstsecondtolast(*stack);
	if (!s_to_last)
		return ;
	last = s_to_last->next;
	s_to_last->next = NULL;
	push(stack, last);
}

void	rra(t_list **_a, t_list **_b)
{
	(void)_b;
	reverse_rotate(_a);
}

void	rrb(t_list **_a, t_list **_b)
{
	(void)_a;
	reverse_rotate(_b);
}

void	rrr(t_list **_a, t_list **_b)
{
	reverse_rotate(_a);
	reverse_rotate(_b);
}
