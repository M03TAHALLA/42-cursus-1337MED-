#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *element ;
	element = malloc(sizeof(t_list));
	element->content = content;
	element->next = NULL;

	return element;
}
