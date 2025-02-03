#include "../includes/checker_bonus.h"
#include <stdio.h>
#include <string.h>

#define SIZE 12

typedef	struct op_s
{
	char	key[4];
	void (*operation)(t_list **, t_list **);
} op_t;

unsigned int hash(char *key)
{
	int				len;
	unsigned int	hash_value;
	int				i;

	len = ft_strlen(key);
	hash_value = 0;
	i = 0;
	while (i < len)
	{
		hash_value += key[i] + ((key[i]%2) * 32);
		hash_value = (hash_value * key[i]) % SIZE;
		i++;
	}
	
	return (hash_value);
}

t_bool	insert(op_t **hash_table, char *key, void (*f)(t_list **, t_list **))
{
	unsigned int index;
	op_t	*element;

	element = malloc(1 * sizeof(op_t));
	if (!element)
		return (FALSE);
	strcpy(element->key, key);
	element->operation = f;
	index = hash(key);
	while (hash_table[index] != NULL)
	{
		index = (index + 1) % SIZE;
	}
	hash_table[index] = element;
	return (TRUE);	
}

void free_hash_table(op_t **hash_table)
{
	unsigned int index;
	int	i;

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
void	init(op_t **hash_table)
{
	int	i;

	i = SIZE;
	while (i--)
		hash_table[i] = NULL;
}

t_bool	acces(op_t **hash_table, char *key, t_list **_a, t_list **_b)
{
	unsigned int index;

	index = hash(key);
	while (strcmp(hash_table[index]->key, key) != 0)
	{
		index = (index + 1) % SIZE;
	}
	return (hash_table[index]->operation(_a,_b), TRUE);
}
void	test(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
	printf("test");
}
int	main(void)
{
	op_t	*hash_table[12];

	init(hash_table);
	insert(hash_table, "sa", sa);
	insert(hash_table, "sb", sb);
	insert(hash_table, "ss", ss);
	insert(hash_table, "ra", ra);
	insert(hash_table, "rb", rb);
	insert(hash_table, "rr", rr);
	insert(hash_table, "rra", rra);
	insert(hash_table, "rrb", rrb);
	insert(hash_table, "rrr", rrr);
	insert(hash_table, "pa", pa);
	insert(hash_table, "pb", pb);
	insert(hash_table, "err", test);
	// print(hash_table);
	acces(hash_table, "err", NULL, NULL);
	free_hash_table(hash_table);
	return (0);
}
