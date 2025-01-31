/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:34 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 21:39:52 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*closest_to_thetop(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (min_moves(min) > min_moves(stack))
			min = stack;
		stack = stack->next;
	}
	min->cheapest = TRUE;
	min->target->cheapest = TRUE;
	return (min);
}

void	final_touch(t_list **_a)
{
	t_list	*small;

	indexing(*_a, ft_lstsize(*_a));
	small = the_smallest_nb(*_a);
	while (small->above == TRUE && (*_a)->content != small->content)
		ra(_a);
	while (small->above == FALSE && (*_a)->content != small->content)
		rra(_a);
}

void	settingtarget_to_b(t_list *_a, t_list *_b)
{
	t_list	*curr_b;
	t_list	*target;
	t_list	*bigger;
	long	content_tar;

	bigger = the_bigger_nb(_b);
	while (_a)
	{
		content_tar = LONG_MIN;
		curr_b = _b;
		while (curr_b)
		{
			if (_a->content > curr_b->content && curr_b->content > content_tar)
			{
				target = curr_b;
				content_tar = target->content;
			}
			curr_b = curr_b->next;
		}
		if (content_tar == LONG_MIN)
			target = bigger;
		_a->target = target;
		_a = _a->next;
	}
	return ;
}

void	transfernumbers_to_b(t_list **_a, t_list **_b)
{
	int	sz_a;
	int	sz_b;

	sz_a = ft_lstsize(*_a);
	if ((sz_a) != 4)
		pb(_a, _b);
	pb(_a, _b);
	sz_a = ft_lstsize(*_a);
	while (sz_a > 3)
	{
		sz_b = ft_lstsize(*_b);
		indexing(*_a, sz_a);
		indexing(*_b, sz_b);
		settingtarget_to_b(*_a, *_b);
		do_op_to_top(_a, _b, closest_to_thetop(*_a), 'b');
		pb(_a, _b);
		sz_a = ft_lstsize(*_a);
	}
}

void	sort_stack(t_list **_a, t_list **_b)
{
	int	sz_a;

	if (is_sorted(*_a))
		return ;
	transfernumbers_to_b(_a, _b);
	tree_nmbrs(_a);
	returnnumbers_to_a(_a, _b);
	final_touch(_a);
	return ;
}
