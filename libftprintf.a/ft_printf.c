/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:58:35 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/19 23:22:07 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	pr_check_format(char *format, va_list ap);
int		ft_printf(const char *format, ...);


void	pr_check_format(char *format, va_list ap)
{
	
}

int	ft_printf(const char * format, ...)
{
	va_list ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*(format + len) != '\0')
	{
		if (*format == '%')
			pr_check_format(format, ap);
		else
			write(1, format, 1);
		len++;
	}
}

int	main()
{
	ft_printf("%d, %i, %c, %s, %x, %X", 1, 2, '3', '45', 6, 7);
}