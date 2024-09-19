#include "libft.h" // Assurez-vous que ce fichier d'en-tête contient les prototypes des fonctions que vous utilisez.
#include <stdio.h>
int main()
{
	int a = 50;
    void *content = &a;
    t_list *list = ft_lstnew(content);
    
    printf("%d",*(int *)(list->content));

    return 0;
}
