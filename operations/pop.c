#include "../includes/push_swap.h"

t_list	*pop(t_list **stack)
{
    t_list *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    return (tmp);
}