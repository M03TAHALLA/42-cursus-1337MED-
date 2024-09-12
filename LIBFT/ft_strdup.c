#include "libft.h"
char *ft_strdup(const char *s)
{
    char *str;

    str = malloc(ft_strlen(s));
    if(str  == NULL)
        return NULL;
    ft_memcpy(str,s,ft_strlen(s));
    return str;
}
