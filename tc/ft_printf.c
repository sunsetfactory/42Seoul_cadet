#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *c, ...);
void	pr_print(char c, int *len);
void	pr_print_s(char *s, int *len);
void	pr_print_p(unsigned long long p, int *len, int sign);
void	pr_print_d(long long d, int *len);
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
	if (s == NULL)
	{
		*len += 6;
		if (write(1, "(null)", 6) == -1)
			*len = -1;
		return ;
	}
	if (*s != '\0')
	{
		pr_print(*s, len);
		pr_print_s(++s, len);
	}
}

void	pr_print_p(unsigned long long p, int *len, int sign)
{
	if (sign == 1)
	{
		pr_print('0', len);
		pr_print('x', len);
		sign = 0;
	}
	if (p >= 16)
	{
		pr_print_p(p / 16, len, sign);
		pr_print_p(p % 16, len, sign);
	}
	else
		pr_print("0123456789abcdef"[p], len);
}

void	pr_print_d(long long d, int *len)
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
	if (u >= 10)
	{
		pr_print_u(u / 10, len);
		pr_print_u(u % 10, len);
	}
	else
		pr_print("0123456789"[u], len);
}

void	pr_print_x(long long x, int *len)
{
	if (x >= 16)
	{
		pr_print_x(x / 16, len);
		pr_print_x(x % 16, len);
	}
	else
		pr_print("0123456789abcdef"[x], len);
}

void	pr_print_lx(long long lx, int *len)
{
	if (lx >= 16)
	{
		pr_print_lx(lx / 16, len);
		pr_print_lx(lx % 16, len);
	}
	else
		pr_print("0123456789ABCDEF"[lx], len);
}

void	pr_gatef(va_list *ap, char *format, int *len)
{
	if (*format == 'c')
		pr_print(va_arg(*ap, int), len);
	if (*format == 's')
		pr_print_s(va_arg(*ap, void *), len);
	if (*format == 'p')
		pr_print_p(va_arg(*ap, unsigned long long), len, 1);
	if (*format == 'd' || *format == 'i')
		pr_print_d((long long)va_arg(*ap, int), len);
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
		if (len == -1)
			return (-1);
		++format;
	}
	return (len);
}

int	main ()
{
	char * test_p1 = "";
	char * test_p2 = "ab";
	char * test_p3 = NULL;
	char * test_p4 = "cd";
	// printf("or_len type d : %d\n", printf("or_pr : %d, %d, %d\n", -11, -2147483648, 10));
	// printf("ft_len type d : %d\n", ft_printf("ft_pr : %d, %d, %d\n", -11, -2147483648, 10));
	// printf("or_len type x : %d\n", printf("or_pr : %x, %x, %x\n", -11, 1886717125, 256));
	// printf("ft_len type x : %d\n", ft_printf("ft_pr : %x, %x, %x\n", -11, 1886717125, 256));
	// printf("or_len type p : %d\n", printf("or_pr : %p, %p, %p\n", test_p1, test_p2, test_p3));
	// printf("ft_len type p : %d\n", ft_printf("ft_pr : %p, %p, %p\n", test_p1, test_p2, test_p3));
	// printf("or_len type s : %d\n", printf("or_pr : %s, %s, %s\n", test_p1, test_p2, test_p3));
	// printf("ft_len type s : %d\n", ft_printf("ft_pr : %s, %s, %s\n", test_p1, test_p2, test_p3));
	printf("or_len type s : %d\n", printf("#V%u<KQm{*%cmeO0kf\fr%i8:r9W&Oj?%xpp.x9%p%dL.nH\Y%x%c", -2032917104, 136289618, -1075455879, -622093341, (void *)-9133099691315441854, -1664290868, 1886717125, 237624882));
	printf("ft_len type s : %d\n", ft_printf("#V%u<KQm{*%cmeO0kf\fr%i8:r9W&Oj?%xpp.x9%p%dL.nH\Y%x%c", -2032917104, 136289618, -1075455879, -622093341, (void *)-9133099691315441854, -1664290868, 1886717125, 237624882));
}