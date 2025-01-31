#include "../includes/push_swap.h"

void    settingTarget_to_a(t_list *_a, t_list *_b)
{
    t_list      *curr_a;
    t_list      *target;
    t_list      *smallest;
    long        theNearest;

    smallest = the_smallest_nb(_a);
    while (_b)
    {
        theNearest = LONG_MAX;
        curr_a = _a;
        while (curr_a)
        {
            if (_b->content < curr_a->content && curr_a->content < theNearest)
            {
                target = curr_a;
                theNearest = target->content;
            }
            curr_a = curr_a->next;
        }
        if (theNearest == LONG_MAX)
            target = smallest;
        _b->target = target;
        _b = _b->next;
    }
    return ;
}
void    ReturnNumbers_to_A(t_list **_a, t_list **_b)
{
    int sz_a;
    int sz_b;

    while ((sz_b = ft_lstsize(*_b)))
    {
        sz_a = ft_lstsize(*_a);
        indexing(*_a, sz_a);
        indexing(*_b, sz_b);
        settingTarget_to_a(*_a, *_b);
        do_op_to_top(_a, _b, closest_to_theTop(*_b), 'a');
        pa(_a, _b);
    }
}