/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:20:55 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/01 10:57:32 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

void	free_stacks(t_list **_a, t_list **_b, t_bool err)
{
	if (_a)
		ft_lstclear(_a);
	if (_b)
		ft_lstclear(_b);
	if (err == TRUE)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return ;
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
