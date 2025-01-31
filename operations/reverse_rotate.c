/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:44:52 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/23 13:45:37 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_list **stack)
{
    t_list  *s_to_last;
    t_list  *last;

    if (!(s_to_last = ft_lstsecondtolast(*stack)))
        return ;
    last = s_to_last->next;
    s_to_last->next = NULL;
    push(stack, last);
}

void    rra(t_list   **stack)
{
    reverse_rotate(stack);
    printf("rra\n");
}

void    rrb(t_list   **stack)
{
    reverse_rotate(stack);
    printf("rrb\n");
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    printf("rrr\n");
}