#include "libft.h"
int check_sep(char c, char sep)
{
    if(sep == c)
        return 1;
    return 0;
}

int count_strings(char const *str,char sep)
{
        int count;
        
        count = 0;
        while(*str != '\0' && check_sep(*str,sep) == 1)
                str++;
        if(*str != '\0')
                count++;
        while(*str != '\0' && check_sep(*str,sep) == 0)
                str++;
        return count;
}

int word_len(char const *str ,char sep)
{
        int i ;
        
        i = 0;
        while(str[i] != '\0' && check_sep(str[i],sep) == 0)
                i++;
        return i;
}

char *ft_word(char const *str,char sep)
{
        char *word;
        int i ;
        int lenght_word;
        
        lenght_word = word_len(str,sep);
        word = malloc( lenght_word + 1);
        i = 0;
        while(i < lenght_word)
        {
                word[i] = str[i];
                i++;
        }
        word[i] = '\0';
        return word;
}
char **ft_split(char const *str, char sep)
{
        char **strings;
        int i ;
        int count_string = count_strings(str,sep);

        i = 0;
        strings = (char **)malloc(sizeof(char *) * count_string + 1);
	if(!strings)
		return NULL;
        while(*str != '\0')
        {
            while(*str != '\0' && check_sep(*str,sep) == 1)
                str++;
            if(*str != '\0')
	    {
                strings[i] = ft_word(str,sep);
                i++;
	    }
            while(*str != '\0' && check_sep(*str,sep) == 0)
                str++;
        }
        strings[i] = 0;
        return strings;
}
