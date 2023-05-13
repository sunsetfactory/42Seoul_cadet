#include <stdarg.h>
#include <stdio.h>

void print_fun(va_list *ap)
{
    printf("%d\n", va_arg(*ap, int));
}
int test_fun(char *c, ...)
{
    va_list ap;
    int nb = 0;

    va_start(ap, c);
    while (nb<3)
    {
        print_fun(&ap);
        nb++;
    }
}

int main ()
{
    test_fun("10, 10, 10", 11, 12, 13);
}