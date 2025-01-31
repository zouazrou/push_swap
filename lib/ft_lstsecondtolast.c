#include "../includes/push_swap.h"

t_list	*ft_lstsecondtolast(t_list *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}