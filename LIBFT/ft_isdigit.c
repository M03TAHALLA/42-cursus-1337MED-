#include "libft.h"

int ft_isdigit(int c)
{
	unsigned char num = (unsigned char)c;
	if(num >= '0' && num <= '9')
		return 1;
	return 0;
}
