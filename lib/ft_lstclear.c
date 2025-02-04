/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:04:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:26:13 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*previous;
	t_list	*current;

	if (!lst || !*lst)
		return ;
	previous = *lst;
	current = *lst;
	while (previous)
	{
		current = current->next;
		ft_lstdelone(previous);
		previous = current;
	}
	*lst = NULL;
}
