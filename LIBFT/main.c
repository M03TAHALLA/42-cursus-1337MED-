#include <stdio.h>
#include "libft.h"
int main() {
    

    char *c1 = malloc(sizeof(char));
    char *c2 = malloc(sizeof(char));
    int *c3 = malloc(sizeof(int));
    int *c4 = malloc(sizeof(int));


    *c1 = 'e';
    *c2 = 'd';
    *c3 = 'f';
    *c4 = 'k';

    t_list *node1 = ft_lstnew(c1);
    t_list *node2 = ft_lstnew(c2);
    t_list *node3 = ft_lstnew(c3);
    t_list *node4 = ft_lstnew(c4);
    t_list *head = NULL; // Initialize head to NULL
    
    head = node1;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
    ft_lstadd_front(&head,node4);

    t_list *ptr = head;
    while (ptr != NULL) {
        printf("%c\n", *(char *)(ptr->content)); // Cast content to char* and dereference
        ptr = ptr->next;
    }
    t_list *lastnode = ft_lstlast(head);
    printf("%c\n", *(char *)(lastnode->content));
    
    int count = ft_lstsize(head);
    printf("%d",count);

    // Free allocated memory
    free(c1);
    free(c2);
    free(c3);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

