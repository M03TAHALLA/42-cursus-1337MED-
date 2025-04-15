#include "libft.h"

static int	skip_sign(char s)
{
	int		sign;

	sign = 1;
	if (s == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	long		num;
	int			sign;

	num = 0;
	if (*str == '\0')
		return (0);
	while (ft_strchr(" \t\v\n\f\r", *str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = skip_sign(*str++);
	while (*str >= '0' && *str <= '9')
	{
		if (num > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(num * sign));
}
