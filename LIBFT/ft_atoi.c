#include "libft.h"

int ft_atoi(const char *str)
{
    int Value;
    int sign;
    
    Value = 0;
    sign = 1;
    if(*str == '-')
    {
        sign = -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        Value = Value * 10 + (*str - '0'); 
        str++;
    }
    return Value * sign;
}
