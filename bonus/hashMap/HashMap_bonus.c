/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HashMap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:20:54 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/05 09:46:43 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

unsigned int	hash(char *key)
{
	int				len;
	unsigned int	hash_value;
	int				i;

	len = ft_strlen(key);
	hash_value = 0;
	i = 0;
	while (i < len)
	{
		hash_value += key[i] + ((key[i] % 2) * 32);
		hash_value = (hash_value * key[i]) % SIZE;
		i++;
	}
	return (hash_value);
}

t_bool	insert(t_op **hash_table, char *key, void (*f)(t_list **, t_list **))
{
	unsigned int	index;
	t_op			*element;
	int				flag;

	if (!key)
		return (FALSE);
	flag = SIZE;
	element = malloc(1 * sizeof(t_op));
	if (!element)
		return (FALSE);
	ft_strcpy(element->key, key);
	element->operation = f;
	index = hash(key);
	while (hash_table[index] != NULL)
	{
		index = (index + 1) % SIZE;
		if (!--flag)
			return (FALSE);
	}
	hash_table[index] = element;
	return (TRUE);
}

void	free_hash_table(t_op **hash_table)
{
	unsigned int	index;
	int				i;

	index = hash(hash_table[0]->key);
	i = 0;
	while (i++ < SIZE)
	{
		if (hash_table[index])
		{
			free(hash_table[index]);
			hash_table[index] = NULL;
		}
		index = (index + 1) % SIZE;
	}
}

void	init(t_op **hash_table)
{
	int	i;

	i = SIZE;
	while (i--)
		hash_table[i] = NULL;
}

t_bool	acces(t_op **hash_table, char *key, t_list **_a, t_list **_b)
{
	unsigned int	index;
	unsigned int	flag;

	index = hash(key);
	flag = SIZE;
	while (ft_strcmp(hash_table[index]->key, key) != 0)
	{
		index = (index + 1) % SIZE;
		if (!--flag)
			return (FALSE);
	}
	return (hash_table[index]->operation(_a, _b), TRUE);
}
