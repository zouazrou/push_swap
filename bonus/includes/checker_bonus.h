/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:41 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/04 13:37:18 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h> // macros
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

# define SIZE 20

typedef int			t_bool;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef	struct op_s
{
	char	key[4];
	void	(*operation)(t_list **, t_list **);
}			op_t;

// linked list for implementation of stack

t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstsecondtolast(t_list *lst);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);

// utils ...

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
long				ft_atoi(const char *nptr);
char				**ft_split(char const *s, char c);
int					ft_max(int n1, int n2);
int					ft_min(int n1, int n2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_abs(int n);

// handing the errors

void				ft_free_array(char **arr);
void				free_stacks(t_list **_a, t_list **_b, int flag);
void				stack_initialization(t_list **stack, int ac, char **av);
t_bool				isduplicate(t_list *stack);
// utils operations

void				swap(t_list **stack);
t_list				*pop(t_list **stack);
void				push(t_list **stack, t_list *element);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
int					is_sorted(t_list *curr);

// operations

void				pb(t_list **_a, t_list **_b);
void				pa(t_list **_a, t_list **_b);
void				sa(t_list **_a, t_list **_b);
void				sb(t_list **_a, t_list **_b);
void				ss(t_list **_a, t_list **_b);
void				ra(t_list **_a, t_list **_b);
void				rb(t_list **_a, t_list **_b);
void				rr(t_list **_a, t_list **_b);
void				rra(t_list **_a, t_list **_b);
void				rrb(t_list **_a, t_list **_b);
void				rrr(t_list **_a, t_list **_b);

// hash map
void	init(op_t **hash_table);
unsigned int	hash(char *key);
t_bool	acces(op_t **hash_table, char *key, t_list **_a, t_list **_b);
t_bool	insert(op_t **hash_table, char *key, void (*f)(t_list **, t_list **));
void free_hash_table(op_t **hash_table);

#endif
