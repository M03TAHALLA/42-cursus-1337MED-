#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*pointer;

	if (!lst || !new)
		return ;
	pointer = *lst;
	*lst = new;
	new->next = pointer;
}
