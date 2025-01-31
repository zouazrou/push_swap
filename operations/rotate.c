/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:42:08 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/23 13:42:55 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **stack)
{
    t_list  *first;

    if (!(*stack)->next)
        return ;
    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;
    ft_lstlast(*stack)->next = first;
}

void    ra(t_list   **stack)
{
    rotate(stack);
    printf("ra\n");
}

void    rb(t_list   **stack)
{
    rotate(stack);
    printf("rb\n");
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    printf("rr\n");
}