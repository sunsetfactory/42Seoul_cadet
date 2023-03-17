#include <stddef.h>

void *ft_memset(void *b, int c, size_t len)
{
    size_t i;
    unsigned char   *a;

    a = (unsigned char)b;
    i = 0;
    while(i < len)
    {
        a[i] = c;
        i++;
    }
    return (a);
}