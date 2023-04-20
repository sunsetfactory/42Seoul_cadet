/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:58:35 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/20 15:47:54 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	pr_check_format(char *format, va_list ap);
int		ft_printf(const char *format, ...);
int		pr_print_pxX(unsigned long long nb, int *len, char *format);
int		pr_print_diu(long long nb, int *len, char *format);

int	pr_print_pxX(unsigned long long nb, int *len, char *format)
{
	if (nb >= 16)
	{
		if (pr_print_pxX(nb / 16, len, format) == -1)
			return (-1);
		pr_print_pxX(nb % 16, len, format);
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

int	pr_print_diu(long long nb, int *len, char *format)
{
	if (nb == -2147483648)
	{
		len += 2;
		if (write(1, "-2", 2) == -1)
			return (-1);
		nb = 147483648;
	}
	if (nb >= 10)
	{
		if (pr_print_diu(nb / 10, len, format))
			return (-1);
		pr_print_diu(nb % 10, len, format);
	}
	else
	{
		++len;
		if (write(1, ('0' + (unsigned int)nb), 1) == -1)
			return (-1);
	}
}

void	pr_check_separator(char *format, va_list ap, int *len)
{
	if (*format == 'x' || *format == 'X' || *format == 'p')
	{
		if (*format == 'p')
			*len += write(1, "0x", 2);
		pr_print_pxX((unsigned long long)va_arg(ap, char *), len, format);
	}
	if (*format == 'd' || *format == 'i' || *format == 'u')
		pr_print_diu((long long)va_arg(ap, long long), len, format);
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
	unsigned int u;

	u = 4294967295;
	printf("%u", u);
	// printf("test1_ft_re : %d\n", ft_printf("TEST1_ft_wr : %x, %X, %p, %%\n", 31, 31, pp));
	// printf("test1_or_re : %d\n", printf("TEST1_or_wr : %x, %X, %p, %%\n", 31, 31, pp));
}