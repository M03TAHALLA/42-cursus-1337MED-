#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *p;

    p = malloc(nmemb * size);
    ft_bzero(p,size * nmemb);
    return p;
}
