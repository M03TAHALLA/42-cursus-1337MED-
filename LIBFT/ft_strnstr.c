#include "libft.h"

char *ft_strnstr(const char *str, const char *to_find,size_t lenght)
{
    const char *pointer_str;
    const char *pointer_find ;
    int count;

    pointer_str = str;
    while (lenght > 0)
    {
        pointer_find = to_find;
        count = 0;
        while (*pointer_find == *pointer_str && *pointer_find != '\0' && *pointer_str != '\0' && lenght > 0)
        {
            count++;
            pointer_find++;
            pointer_str++;
            lenght--;
        }
        if(*pointer_find == '\0')
            return (char *)(pointer_str - count);
        if(lenght == 0)
            break;
        pointer_str = pointer_str + 1 ;
        lenght--;
    }
    return NULL ;
}
