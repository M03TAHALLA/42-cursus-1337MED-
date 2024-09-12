#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *destp = dest;
    const unsigned char *srcp = src;
    while(n > 0){
        *destp = *srcp;
        destp++;
        srcp++;
        n--;
    }
    return dest;
}
