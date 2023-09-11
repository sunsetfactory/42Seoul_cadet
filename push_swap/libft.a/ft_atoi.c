/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:40:30 by seokjyan          #+#    #+#             */
/*   Updated: 2023/09/11 23:54:05 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char *str)
{
	return ((*str >= 9 && *str <= 13) || *str == 32);
}

static int	help_atoi(char *str, int *c)
{
	char	*tmp;

	tmp = str;
	while (ft_isspace(tmp))
	{
		tmp++;
	}
	while (*tmp == '+' || *tmp == '-')
	{
		if (*tmp == '-')
			*c = -*c;
		tmp++;
	}
	return (tmp - str);
}

int	ft_atoi(const char *str)
{
	char	*cp_str;
	int		res;
	int		c;

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
