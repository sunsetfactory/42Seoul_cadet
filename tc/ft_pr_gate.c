/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_gate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:34:59 by seokjyan          #+#    #+#             */
/*   Updated: 2023/06/26 17:21:35 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_print_p(unsigned long long p, int *len, int sign)
{
	if (sign == 1)
	{
		if (pr_print('0', len) == -1)
			return (-1);
		if (pr_print('x', len) == -1)
			return (-1);
		sign = 0;
	}
	if (p >= 16)
	{
		if (pr_print_p(p / 16, len, sign) == -1)
			return (-1);
		if (pr_print_p(p % 16, len, sign) == -1)
			return (-1);
	}
	else
		if (pr_print("0123456789abcdef"[p], len) == -1)
			return (-1);
	return (1);
}

int	pr_print_di(long long d, int *len)
{
	if (d < 0)
	{
		d = -d;
		if (pr_print('-', len) == -1)
			return (-1);
	}
	if (d >= 10)
	{
		if (pr_print_di(d / 10, len) == -1)
			return (-1);
		if (pr_print_di(d % 10, len) == -1)
			return (-1);
	}
	else
		if (pr_print("0123456789"[d], len) == -1)
			return (-1);
	return (1);
}

int	pr_print_u(unsigned int u, int *len)
{
	if (u >= 10)
	{
		if (pr_print_u(u / 10, len) == -1)
			return (-1);
		if (pr_print_u(u % 10, len) == -1)
			return (-1);
	}
	else
		if (pr_print("0123456789"[u], len) == -1)
			return (-1);
	return (1);
}

int	pr_print_x(unsigned int x, int *len)
{
	if (x >= 16)
	{
		if (pr_print_x(x / 16, len) == -1)
			return (-1);
		if (pr_print_x(x % 16, len) == -1)
			return (-1);
	}
	else
		if (pr_print("0123456789abcdef"[x], len) == -1)
			return (-1);
	return (1);
}

int	pr_print_lx(unsigned int lx, int *len)
{
	if (lx >= 16)
	{
		if (pr_print_lx(lx / 16, len) == -1)
			return (-1);
		if (pr_print_lx(lx % 16, len) == -1)
			return (-1);
	}
	else
		if (pr_print("0123456789ABCDEF"[lx], len) == -1)
			return (-1);
	return (1);
}
