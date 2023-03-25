/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:01:14 by seokjyan          #+#    #+#             */
/*   Updated: 2023/03/25 17:51:05 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long n)
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
	long	cp_n;
	char	*res;
	int		len;

	cp_n = (long)n;
	len = ft_numlen(cp_n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	*(res + len) = '\0';
	len -= 1;
	if (cp_n < 0){
		*res = '-';
		len -= 1;
		cp_n *= -1;
	}
	while (cp_n)
	{
		*(res + len) = (cp_n % 10) + '0';
		cp_n /= 10;
		len--;
	}
	return (res);
}
