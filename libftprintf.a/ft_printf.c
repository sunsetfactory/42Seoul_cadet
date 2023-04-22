/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:58:35 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/22 21:39:02 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	pr_check_format(char *format, va_list ap);
int		ft_printf(const char *format, ...);
int		pr_print_diupxX(unsigned long long nb, int *len, char *format);
void	pr_check_separator(char *format, va_list ap, int *len);

int	pr_print_diupxX(unsigned long long nb, int *len, char *format)
{
	unsigned long long base;

	base = 16;
	if (*format == 'd' || *format == 'i' || *format == 'u')
		base = 10;
	if (nb >= base)
	{
		if (pr_print_diupxX(nb / base, len, format) == -1)
			return (-1);
		pr_print_diupxX(nb % base, len, format);
	}
	else if (*format != 'X')
	{
		++(*len);
		if (write(1, &"0123456789abcdef"[nb], 1) == -1)
			return (-1);
	}
	else
	{
		++(*len);
		if (write(1, &"0123456789ABCDEF"[nb], 1) == -1)
			return (-1);
	}
	return (0);
}
int	pr_print_sc(char *s)
{
	char *p;

	p = s;
	while (*(p))
	{
		write(1, p, 1);
		p++;
	}
	return (p - s);
}

void	pr_check_separator(char *format, va_list ap, int *len)
{
	long long	nb;

	if (*format == 'x' || *format == 'X' || *format == 'p' \
	|| *format == 'd' || *format == 'i' || *format == 'u')
	{
		if (*format == 'p')
			*len += write(1, "0x", 2);
		if (*format == 'u')
			nb = va_arg(ap, long long);
		else if (*format == 'x' || *format == 'X' || *format == 'p')
			nb = (long long)va_arg(ap, char *);
		else 
			nb = (long long)va_arg(ap, int);
		if (nb < 0)
		{
			*len += write(1, "-", 1);
			nb = -(nb);
		}
		pr_print_diupxX((unsigned long long)nb, len, format);
	}
	else if (*format == 's' || *format == 'c')
	{
		*len += pr_print_sc((char *)va_arg(ap, char *));
	}
	if (*format == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char * format, ...)
{
	va_list ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			pr_check_separator((char *)(++format), ap, &len);
		else
		{
			++len;
			write(1, format, 1);
		}
		++format;
	}
	return (len);
}

#include <stdio.h>

int	main()
{
	char *pp;
	printf("%d\n",ft_printf("%d  :", -12));
	printf("%d\n",ft_printf("%i  :", -13));
	printf("%d\n",ft_printf("%u  :", -14));
	printf("%d\n",ft_printf("%x  :", -15));
	printf("%d\n",ft_printf("%X  :", -16));
	printf("%d\n",ft_printf("%p  :", -17));
	printf("%d\n",ft_printf("%%  :", -18));
	// printf("test1_ft_re : %d\n", ft_printf("TEST1_ft_wr : %d, %i, %u, %x, %X, %p, %%\n", -11, 12, -13, 31, 31, pp));
	// printf("test1_or_re : %d\n", printf("TEST1_or_wr : %d, %i, %u, %x, %X, %p, %%\n", -11, 12, -13, 31, 31, pp));
}