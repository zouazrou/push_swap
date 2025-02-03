/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:04:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/22 11:35:46 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
