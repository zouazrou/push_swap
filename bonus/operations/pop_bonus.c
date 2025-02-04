/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:47 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:22:04 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_list	*pop(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	return (tmp);
}
