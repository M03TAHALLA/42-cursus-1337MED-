#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t dst_size;
    size_t src_size;
    size_t j;

    if (!src && !dst)
        return (0);

    dst_size = ft_strlen(dst);
    src_size = ft_strlen(src);

    if (size <= dst_size)
        return (src_size + size);

    i = 0;
    j = dst_size;

    while (src[i] != '\0' && i < (size - 1 - dst_size)) {
        dst[j] = src[i];
        j++;
        i++;
    }

    dst[j] = '\0';

    return (src_size + dst_size);
}

