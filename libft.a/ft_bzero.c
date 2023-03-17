#include <stddef.h>

void bzero(void *s, size_t n)
{
    size_t i;

    (unsigned char*)s;
    i = 0;
    while(i < n)
    {
        s[i] = 0;
        i++;
    }
}