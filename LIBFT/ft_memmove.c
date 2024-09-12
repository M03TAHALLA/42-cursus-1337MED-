#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if(!dest && !src)
		return 0;
	unsigned char *destp;
	const unsigned char *srcp;
	if(dest > src)
	{
		destp = dest + n;
		srcp = src + n;
		while(n > 0){
			*--destp = *--srcp;
			n--;
		}
	}else{
		destp = dest;
		srcp = src;
		 while(n > 0){                                                                                                                   *destp++ = *srcp++;
                        n--;                                                                                                            }
	}
	return dest;
}
