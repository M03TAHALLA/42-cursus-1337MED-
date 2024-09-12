#include "libft.h"

int lenght_num(int n)
{
       int count;

        count = 0;
        if( n < 0)
                n = -n;
        while(n > 0)
        {
                n = n / 10;
                count++;
        }
        return count;
}

char *ft_itoa(int n)
{
    if(n == 0)
        return "0\0";
    if( n == -2147483648)
        return "-2147483648\0";
    int lenght ;
    char *number;

    lenght = lenght_num(n);
    if(n < 0)
    {
        number = malloc(sizeof(char) * lenght + 2);
        number[0] = '-';
        number[lenght + 1] = '\0';
        n = -n;
        while(n > 0)
        {
            number[lenght--] = (n % 10) + '0';
            n = n / 10;
        }
    }
    else
    {
        number = malloc(sizeof(char) * lenght + 1);
        number[lenght] = '\0';
        while(n > 0)
        {
            number[--lenght] = (n % 10) + '0';
            n = n / 10;
        }
    }
    return number;
}
