/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:15 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 17:38:59 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *curr)
{
	t_list	*nx;

	nx = curr->next;
	while (nx)
	{
		if (curr->content > nx->content)
			return (0);
		curr = curr->next;
		nx = nx->next;
	}
	return (1);
}
