#include "../includes/push_swap.h"

void    print(t_list *a, t_list *b)
{
    printf("------------------------------\nstack (A)\n");
    while (a)
    {
        printf("(%d)->", a->content);
        a = a->next;
    }
    printf("0x0\n");
    printf("\nstack (B)\n");
    while (b)
    {
        printf("(%d)->", b->content);
        b = b->next;
    }
    printf("0x0\n------------------------------\n");
}
void    settingTarget_to_b(t_list *_a, t_list *_b)
{
    t_list      *curr_b;
    t_list      *target;
    t_list      *bigger;
    long        theNearest;

    bigger = the_bigger_nb(_b);
    while (_a)
    {
        theNearest = LONG_MIN;
        curr_b = _b;
        while (curr_b)
        {
            if (_a->content > curr_b->content && curr_b->content > theNearest)
            {
                target = curr_b;
                theNearest = target->content;
            }
            curr_b = curr_b->next;
        }
        if (theNearest == LONG_MIN)
            target = bigger;
        _a->target = target;
        _a = _a->next;
    }
    return ;
}


void    TransferNumbers_to_B(t_list **_a, t_list **_b)
{
    int sz_a;
    int sz_b;

    sz_a = ft_lstsize(*_a);
    if ((sz_a) != 4)
        pb(_a, _b);
    pb(_a, _b);
    while ((sz_a = ft_lstsize(*_a)) > 3)
    {
        sz_b = ft_lstsize(*_b);
        indexing(*_a, sz_a);
        indexing(*_b, sz_b);
        settingTarget_to_b(*_a,*_b);
        do_op_to_top(_a, _b, closest_to_theTop(*_a), 'b');
        pb(_a, _b);
    }    
}
void    sort_stack(t_list **_a, t_list** _b)
{
    int		sz_a;

    if (is_sorted(*_a))
        return ;
    TransferNumbers_to_B(_a, _b);
    tree_nmbrs(_a);
    ReturnNumbers_to_A(_a, _b);
    final_touch(_a);
    return ;
}