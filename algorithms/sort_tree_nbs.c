/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tree_nbs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:27 by zouazrou          #+#    #+#             */
/*   Updated: 2025/01/31 17:38:59 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tree_nmbrs(t_list **_s)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	if (is_sorted(*_s))
		return ;
	f = (*_s);
	s = (*_s)->next;
	t = (*_s)->next->next;
	if (f->content > s->content && f->content > t->content)
		ra(_s);
	else if (s->content > f->content && s->content > t->content)
		rra(_s);
	if (!is_sorted(*_s))
		sa(_s);
	return ;
}
