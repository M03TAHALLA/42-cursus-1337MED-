#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *result;
	size_t i;

	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if(!result)
		return NULL;
	i = 0;
	while(i < ft_strlen(s))
	{
		result[i] = (*f)(i,s[i]);
		i++;
	}
	result[i] = '\0';
	return result;
}
