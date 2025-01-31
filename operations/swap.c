/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:42:11 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/23 13:42:32 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
    t_list  *tmp;

    tmp = (*stack);
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;	
    (*stack)->next = tmp;
}

void    sa(t_list **stack)
{
    swap(stack);
    printf("sa\n");
}

void    sb(t_list **stack)
{
    swap(stack);
    printf("sb\n");
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}