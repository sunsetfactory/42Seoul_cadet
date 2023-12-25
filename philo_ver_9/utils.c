/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:46:50 by minkylee          #+#    #+#             */
/*   Updated: 2023/12/25 22:43:29 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (-1);
	return ((mytime.tv_sec * 1000) + (mytime.tv_usec / 1000));
}

void	ft_usleep(long sleep_time)
{
	long	start;

	start = ft_get_time();
	while (start + (sleep_time * 1) > ft_get_time())
		usleep(100);
}

int	check_argu(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (!ft_atoi(argv[index]))
			return (0);
		index++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	rst;

	sign = 1;
	rst = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rst = rst * 10 + (*str - '0');
		str++;
	}
	if (sign * rst <= 0 || sign * rst > 2147483647)
		return (0);
	return (sign *(int)(rst));
}
