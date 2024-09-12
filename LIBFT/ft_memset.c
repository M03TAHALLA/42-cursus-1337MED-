#include "libft.h"

void *ft_memset(void *table, int value, size_t size)
{
    unsigned char *pointer;
    pointer = table;
    
    while(size > 0){
        *pointer = (unsigned char)value;
        size--;
        pointer++;
    }
    return table;
}
