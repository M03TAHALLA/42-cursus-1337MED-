#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char *t ;
    int found;

    found = 0;
        while(*s != '\0')
        {
                if(*s == (unsigned char) c)
                {
                    t = (char *)s;
                    found = 1;
                }
                s++;
        }
        if(found == 1)
            return t;
        else
            return NULL;
}
