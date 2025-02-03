#include "../includes/checker_bonus.h"

#define SIZE 12
unsigned int hash(char *key)
{
    
}
int main(int ac, char **av)
{
    t_list  *_a;
    t_list  *_b;
    int     size_a;

    stack_initialization(&_a, ac, av + 1);
    _b = NULL;
    size_a = ft_lstsize(_a);
    do_op();
}