#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
        char *SousChaine;
        int i ;
        SousChaine = malloc(len + 1);
	if(!SousChaine)
		return NULL;
        i = 0;
        start = start - 1;
        while(len > 0)
        {
            SousChaine[i++] = s[start++];
            len--;
        }
        SousChaine[i] = '\0';
        return SousChaine;
}
