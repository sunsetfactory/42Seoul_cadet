/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:01:14 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/07 01:22:41 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len += 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	cp_n;
	char		*res;
	int			len;

	cp_n = (long long)n;
	len = ft_numlen(cp_n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	*(res + len) = '\0';
	len -= 1;
	if (cp_n < 0)
	{
		*res = '-';
		cp_n *= -1;
	}
	if (cp_n == 0)
		*(res + len) = '0';
	while (cp_n)
	{
		*(res + len) = (cp_n % 10) + '0';
		cp_n /= 10;
		len--;
	}
	return (res);
}
