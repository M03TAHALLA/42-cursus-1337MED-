#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	mult;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	mult = count * size;
	if (mult == 0)
	{
		str = malloc(0);
		if (!str)
			return (0);
		return (str);
	}
	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero (str, (count * size));
	return (str);
}
