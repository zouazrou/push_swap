/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:20:55 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 18:30:10 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	isduplicate(t_list *stack)
{
	t_list	*curr;

	while (stack)
	{
		curr = stack->next;
		while (curr)
		{
			if (stack->content == curr->content)
				return (TRUE);
			curr = curr->next;
		}
		stack = stack->next;
	}
	return (FALSE);
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
