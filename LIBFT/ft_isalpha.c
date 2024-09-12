#include "libft.h"

int ft_isalpha(int c)
{
        unsigned char caracter = (unsigned char)c;
        if((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'))
                return 1;
        return 0;
}
