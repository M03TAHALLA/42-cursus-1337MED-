#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int lenght;
	char *conct;
	int i;

	lenght = ft_strlen(s1) + ft_strlen(s2); 
	conct = malloc(lenght + 1);
	i = 0;
	while(*s1 != '\0')
		conct[i++] = *s1++;
	while(*s2 != '\0')
		conct[i++] = *s2++;
	conct[i] = '\0';
	return conct;
}
