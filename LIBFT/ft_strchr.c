#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	while(*s != '\0')
	{
		if(*s == (unsigned char) c){
			return (char *)s;
		}
		s++;
	}
	return NULL;
}
