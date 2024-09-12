#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *srcp = s;
    int found = 0 ;
    while(n > 0)
    {
        if(*srcp == (unsigned char )c){
            found = 1;
            break;
        }
        srcp++;
        n--;
    }
    if(found == 1){
        return (void *)srcp;
    }else{
        return NULL;
    }
}
