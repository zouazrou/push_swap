/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:38:00 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 17:38:59 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*the_bigger_nb(t_list *lst)
{
	t_list	*max;

	max = lst;
	while (lst)
	{
		if (max->content < lst->content)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

t_list	*the_smallest_nb(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if (min->content > lst->content)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
