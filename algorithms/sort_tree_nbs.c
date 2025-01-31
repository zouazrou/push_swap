#include "../includes/push_swap.h"


void    tree_nmbrs(t_list **_s)
{
    t_list *f;
    t_list *s;
    t_list *t;

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