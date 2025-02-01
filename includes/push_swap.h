/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:41 by zouazrou          #+#    #+#             */
/*   Updated: 2025/02/01 11:23:55 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> // macros
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef int			t_bool;

typedef struct s_list
{
	int				content;
	int				index;
	t_bool			cheapest;
	t_bool			above;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

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
void				do_op_to_top(t_list **_a, t_list **_b, t_list *node,
						char flag);
void				do_rr(t_list **_a, t_list **_b);
void				do_rrr(t_list **_a, t_list **_b);
void				just_do_a(t_list **_a, t_list **_b, t_list *node);
void				just_do_b(t_list **_a, t_list **_b, t_list *node);
void				final_touch(t_list **_a);

// operations

void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack);
void				ra(t_list **stack);
void				rb(t_list **stack);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack);
void				rrb(t_list **stack);
void				rrr(t_list **stack_a, t_list **stack_b);

//
t_list				*the_smallest_nb(t_list *lst);
t_list				*the_bigger_nb(t_list *lst);
t_list				*closest_to_thetop(t_list *stack);
void				indexing(t_list *stack, int size);
int					min_moves(t_list *node);
void				returnnumbers_to_a(t_list **_a, t_list **_b);

// algorithms and utils ...
int					is_sorted(t_list *curr);
void				tree_nmbrs(t_list **stack);
// void    five_nmbrs(t_list **stack_a, t_list **stack_b);
void				sort_stack(t_list **stack_a, t_list **stack_b);

#endif
