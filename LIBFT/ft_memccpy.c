#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t size)
{
    int	i = 0;
    const unsigned char *psrc = src;
    int null = 0;
    while(size > 0){
        if(*psrc == (unsigned char)c){
            i++;
            null = 1;
            break;
        }
        psrc++;
        i++;
        size--;
    }
    ft_memcpy(dest,src,i);
    if(null == 1)
        return dest;
    else
        return NULL;
}
