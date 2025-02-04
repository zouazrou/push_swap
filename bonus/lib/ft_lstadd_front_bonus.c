/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:03:59 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:27:33 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		free_stacks(lst, NULL, TRUE);
	new->next = *lst;
	*lst = new;
}
