#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plst;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		plst = *lst;
		while (plst->next != NULL)
		{
			plst = plst->next;
		}
		plst->next = new;
	}
}
