#include "../includes/push_swap.h"

void    l3aml_a(t_list **_a, t_list **_b, t_list *node)
{
    t_list  *target;

    target = node->target;

    while ((*_b)->cheapest == FALSE && node->above == TRUE)
        rb(_b);
    while ((*_b)->cheapest == FALSE && node->above == FALSE)
        rrb(_b);    
    while ((*_a)->cheapest == FALSE && target->above == TRUE)
        ra(_a);
    while ((*_a)->cheapest == FALSE && target->above == FALSE)
        rra(_a);
}

void    l3aml_b(t_list **_a, t_list **_b, t_list *node)
{
    t_list  *target;

    target = node->target;

    while ((*_a)->cheapest == FALSE && node->above == TRUE)
        ra(_a);
    while ((*_a)->cheapest == FALSE && node->above == FALSE)
        rra(_a);    
    while ((*_b)->cheapest == FALSE && target->above == TRUE)
        rb(_b);
    while ((*_b)->cheapest == FALSE && target->above == FALSE)
        rrb(_b);
}

void    do_rrr(t_list **_a, t_list **_b)
{
    while ((*_a)->cheapest == FALSE && (*_b)->cheapest == FALSE)
        rrr(_a, _b);
    while ((*_a)->cheapest == FALSE)
        rra(_a);
    while ((*_b)->cheapest == FALSE)
        rrb(_b); 
}

void    do_rr(t_list **_a, t_list **_b)
{
    while ((*_a)->cheapest == FALSE && (*_b)->cheapest == FALSE)
        rr(_a, _b);
    while ((*_a)->cheapest == FALSE)
        ra(_a);
    while ((*_b)->cheapest == FALSE)
        rb(_b);
}
void    final_touch(t_list **_a)
{
    t_list *small;

    indexing(*_a, ft_lstsize(*_a));
    small = the_smallest_nb(*_a);
    while (small->above == TRUE && (*_a)->content != small->content)
        ra(_a);
    while (small->above == FALSE && (*_a)->content != small->content)
        rra(_a);    
}
void    do_op_to_top(t_list **_a, t_list **_b, t_list *node, char flag)
{
    t_list  *target;

    target = node->target;
    if (node->above == TRUE && target->above == TRUE)
        do_rr(_a, _b);
    else if (node->above == FALSE && target->above == FALSE)
        do_rrr(_a, _b);
    else if (flag == 'b')
        l3aml_b(_a, _b, node);
    else if (flag == 'a')
        l3aml_a(_a, _b, node);
}