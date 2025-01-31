/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:30 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 21:16:20 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	settingtarget_to_a(t_list *_a, t_list *_b)
{
	t_list	*curr_a;
	t_list	*target;
	t_list	*smallest;
	long	content_tar;

	smallest = the_smallest_nb(_a);
	while (_b)
	{
		content_tar = LONG_MAX;
		curr_a = _a;
		while (curr_a)
		{
			if (_b->content < curr_a->content && curr_a->content < content_tar)
			{
				target = curr_a;
				content_tar = target->content;
			}
			curr_a = curr_a->next;
		}
		if (content_tar == LONG_MAX)
			target = smallest;
		_b->target = target;
		_b = _b->next;
	}
	return ;
}

void	returnnumbers_to_a(t_list **_a, t_list **_b)
{
	int	sz_a;
	int	sz_b;

	sz_b = ft_lstsize(*_b);
	sz_a = ft_lstsize(*_a);
	while (sz_b)
	{
		indexing(*_a, sz_a);
		indexing(*_b, sz_b);
		settingtarget_to_a(*_a, *_b);
		do_op_to_top(_a, _b, closest_to_thetop(*_b), 'a');
		pa(_a, _b);
		sz_a = ft_lstsize(*_a);
		sz_b = ft_lstsize(*_b);
	}
}
