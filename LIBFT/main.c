#include "libft.h" // Assurez-vous que ce fichier d'en-tête contient les prototypes des fonctions que vous utilisez.
#include <stdio.h>

int main(void)
{
    t_list *head = NULL; // Déclaration de la liste vide
    t_list *new_node1;
    t_list *new_node2;
    t_list *new_node3;

    // Allocation de la mémoire et initialisation des noeuds
    new_node1 = ft_lstnew("Node 1");
    new_node2 = ft_lstnew("Node 2");
    new_node3 = ft_lstnew("Node 3");

    // Ajout de noeuds au début de la liste
    ft_lstadd_front(&head, new_node1);
    ft_lstadd_front(&head, new_node2);
    ft_lstadd_front(&head, new_node3);

    // Impression de la liste pour vérifier
    t_list *tmp = head;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    return 0;
}
