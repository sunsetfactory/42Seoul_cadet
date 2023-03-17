#include <stddef.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    unsigned char *tmp_d
    const unsigned char *tmp_s;
    
    tmp_d = dst;
    tmp_s = src;
    i = 0;
    while (i < n)
    {
        tmp_d[i] = tmp_s[i];
        i++;
    }
    return (dst);
}