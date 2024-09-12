#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *s1p;
    const unsigned char *s2p;
    
    s1p = s1;
    s2p = s2;
    while(n > 0)
    {
        if(*s1p < *s2p)
            return -1;
        if(*s1p > *s2p)
            return 1;
        s1p++;
        s2p++;
        n--;
    }
    return 0;
}
