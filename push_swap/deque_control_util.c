/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_control_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:48:11 by seokjyan          #+#    #+#             */
/*   Updated: 2023/09/12 06:47:28 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	help_atoi(char *str, int *c)
{
	char	*tmp;

	tmp = str;
	while (ft_isspace(tmp))
	{
		tmp++;
	}
	if (*tmp == '+' || *tmp == '-')
	{
		if (*tmp == '-')
			*c = -*c;
		tmp++;
	}
	return (tmp - str);
}

static long long	ft_atoll(const char *str)
{
	char			*cp_str;
	long long		res;
	long long		c;

	res = 0;
	c = 1;
	cp_str = (char *)str;
	cp_str += help_atoi(cp_str, &c);
	while ((*cp_str >= '0' && *cp_str <= '9'))
	{
		res = res * 10 + (*cp_str - '0');
		cp_str++;
	}
	return (c * res);
}

int	is_int(const char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}

int	ft_is_digit(const char *str)
{
	if (!str)
		return (0);
	while (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}