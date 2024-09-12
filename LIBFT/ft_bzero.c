#include "libft.h"

void ft_bzero(void *s , size_t size)
{
	ft_memset(s,'\0',size);
}
