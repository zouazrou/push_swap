/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:19:54 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 18:35:52 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../includes/checker_bonus.h"

void	free_all(t_list **_a, t_list **_b, t_bool flag, op_t **table)
{
	char	*line;

	*line = get_next_line(0);
	while ((*line))
	{
		safe_free(line);
		*line = get_next_line(0);
	}
	free_hash_table(table);
	free_stacks(_a, _b, flag);
}

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

t_bool	insert_operations(op_t **hash_table)
{
	init(hash_table);
	if (FALSE == insert(hash_table, "sa\n", sa))
		return (FALSE);
	if (FALSE == insert(hash_table, "sb\n", sb))
		return (FALSE);
	if (FALSE == insert(hash_table, "ss\n", ss))
		return (FALSE);
	if (FALSE == insert(hash_table, "ra\n", ra))
		return (FALSE);
	if (FALSE == insert(hash_table, "rb\n", rb))
		return (FALSE);
	if (FALSE == inserlinet(hash_table, "rr\n", rr))
		return (FALSE);
	if (FALSE == insert(hash_table, "rra\n", rra))
		return (FALSE);
	if (FALSE == insert(hash_table, "rrb\n", rrb))
		return (FALSE);
	if (FALSE == insert(hash_table, "rrr\n", rrr))
		return (FALSE);
	if (FALSE == insert(hash_table, "pa\n", pa))
		return (FALSE);
	if (FALSE == insert(hash_table, "pb\n", pb))
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_list	*_a;
	t_list	*_b;
	char	*line;
	op_t	*hash_table[SIZE];

	stack_initialization(&_a, ac, av + 1);
	_b = NULL;
	if (FALSE == insert_operations(hash_table))
		free_all(&_a, &_b, TRUE, hash_table);
	line = get_next_line(0);
	while ((line))
	{
		if (FALSE == acces(hash_table, line, &_a, &_b))
			return (safe_free(&line), free_all(&_a, &_b, TRUE, hash_table), 1);
		safe_free(&line);
		line = get_next_line(0);
	}
	safe_free(&line);
	if (_b != NULL || !is_sorted(_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free_all(&_a, &_b, FALSE, hash_table);
	return (0);
}
