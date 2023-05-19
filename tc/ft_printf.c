/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:17:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/05/19 22:51:55 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_print(char c, int *len)
{
	++(*len);
	if (write(1, &c, 1) == -1)
	{
		*len = -1;
		return (*len);
	}
	return (1);
}

int	pr_print_s(char *s, int *len)
{
	if (s == NULL)
	{
		*len += 6;
		if (write(1, "(null)", 6) == -1)
		{
			*len = -1;
			return (-1);
		}
	}
	else if (*s != '\0')
	{
		if (pr_print(*s, len) == -1)
			return (-1);
		pr_print_s(++s, len);
	}
	return (1);
}

int	pr_gatef(va_list *ap, char *format, int *len)
{
	if (*format == 'c')
		return (pr_print(va_arg(*ap, int), len));
	if (*format == 's')
		return (pr_print_s(va_arg(*ap, void *), len));
	if (*format == 'p')
		return (pr_print_p(va_arg(*ap, unsigned long long), len, 1));
	if (*format == 'd' || *format == 'i')
		return (pr_print_di((long long)va_arg(*ap, int), len));
	if (*format == 'u')
		return (pr_print_u(va_arg(*ap, unsigned int), len));
	if (*format == 'x')
		return (pr_print_x(va_arg(*ap, unsigned int), len));
	if (*format == 'X')
		return (pr_print_lx(va_arg(*ap, unsigned int), len));
	if (*format == '%')
		return (pr_print(*format, len));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		at;

	va_start(ap, format);
	len = 0;
	at = 1;
	while (*format != '\0')
	{
		if (*format == '%')
			at = pr_gatef(&ap, (char *)(++format), &len);
		else
			pr_print(*format, &len);
		if (len == -1 || at != 1)
			break ;
		++format;
	}
	va_end(ap);
	return (len);
}
