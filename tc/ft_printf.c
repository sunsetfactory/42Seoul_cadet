#include <stdarg.h>
#include <io.h>
#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *c, ...);
void	pr_print(char c, int *len);
void	pr_print_s(char *s, int *len);
void	pr_print_p(unsigned long long p, int *len);
void	pr_print_d(int d, int *len);
void	pr_print_u(unsigned int u, int *len);
void	pr_print_x(long long x, int *len);
void	pr_print_lx(long long lx, int *len);

void	pr_print(char c, int *len)
{
	++(*len);
	if (write(1, &c, 1) == -1)
		*len = -1;
}

void	pr_print_s(char *s, int *len)
{
	while(*s != '\0')
	{
		pr_print(*s, len);
	}
}

void	pr_print_p(unsigned long long p, int *len)
{
	pr_print('0', len);
	pr_print('x', len);
	while (p != 0)
	{
		pr_print("0123456789abcdef"[p / 16], len);
		p %= 16;
	}
}

void	pr_print_d(int d, int *len)
{
	if (d < 0)
	{
		d = -d;
		pr_print('-', len);
	}
	if (d >= 10)
	{
		pr_print_d(d / 10, len);
		pr_print_d(d % 10, len);
	}
	else
		pr_print("0123456789"[d], len);
}

void	pr_print_u(unsigned int u, int *len)
{
	while (u != 0)
	{
		pr_print("0123456789"[u / 10], len);
		u %= 10;
	}
}

void	pr_print_x(long long x, int *len)
{
	while (x != 0)
	{
		pr_print("0123456789abcdef"[x / 10], len);
		x %= 16;
	}
}

void	pr_print_lx(long long lx, int *len)
{
	while (lx != 0)
	{
		pr_print("0123456789ABCDEF"[lx / 10], len);
		lx %= 16;
	}
}

void	pr_gatef(va_list *ap, char *format, int *len)
{
	if (*format == 'c')
		pr_print(va_arg(*ap, int), len);
	if (*format == 's')
		pr_print_s(va_arg(*ap, void *), len);
	if (*format == 'p')
		pr_print_p(va_arg(*ap, unsigned long long), len);
	if (*format == 'd' || *format == 'i')
		pr_print_d(va_arg(*ap, int), len);
	if (*format == 'u')
		pr_print_u(va_arg(*ap, unsigned int), len);
	if (*format == 'x')
		pr_print_x(va_arg(*ap, long long), len);
	if (*format == 'X')
		pr_print_lx(va_arg(*ap, long long), len);
	if (*format == '%')
		pr_print(*format, len);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			pr_gatef(&ap, (char *)(++format), &len);
		else
			pr_print(*format, &len);
		++format;
	}
	return (len);
}

int	main ()
{
	printf("or_len : %d\n", printf("or_pr : %d, %d, %d\n", -11, -10, 10));
	printf("ft_len : %d\n", ft_printf("ft_pr : %d, %d, %d\n", -11, -10, 10));
}