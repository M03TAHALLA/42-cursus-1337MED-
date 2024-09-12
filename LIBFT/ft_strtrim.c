#include "libft.h"

int infunc(char const *str,char c)
{
    while(*str != '\0')
    {
      if(*str == c)
        return 1;
      str++;
    }
    return 0;
}
char *ft_strtrim(char const *s1, char const *set)
{
        char  *pointeurDebut;
        char  *pointeurFin;
        char *str ;

        pointeurFin = (char *)s1 + (ft_strlen(s1) - 1);
        pointeurDebut = (char *)s1;
        while(infunc(set,*pointeurFin) == 1)
            pointeurFin--;
        pointeurFin += 1 ;
        *pointeurFin = '\0';
        while(infunc(set,*pointeurDebut) == 1)
            pointeurDebut++;
        str = malloc(ft_strlen(pointeurDebut) + 1);
	if(!str)
		return NULL;
        ft_strlcpy(str,pointeurDebut,ft_strlen(pointeurDebut) + 1);
        return str;
}
