#include "../includes/push_swap.h"

int is_sorted(t_list *curr)
{
    t_list *nx;

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