#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size){
	size_t srcsize;
	size_t i;
	
	srcsize = ft_strlen(src);
	i = 0;
	if(!dst && !src)
		return 0;
	if(size != 0)
	{
		while(src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return srcsize;
}
