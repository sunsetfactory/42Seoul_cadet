/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:34:08 by minkylee          #+#    #+#             */
/*   Updated: 2023/12/25 22:43:13 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating_count(t_philo *philo, t_table *monitor, int *check_num)
{
	if (philo->num_time_each == 0)
			*check_num += 1;
	if (*check_num == monitor->num_philo)
	{
		monitor->eat_flag = 1;
		pthread_mutex_unlock(philo->time_lock);
		return (0);
	}
	return (1);
}

int	monitoring_sys(t_table *monitor)
{
	int	i;
	int	check_num;

	i = 0;
	check_num = 0;
	while (i < monitor->num_philo)
	{
		pthread_mutex_lock(monitor->philo[i].time_lock);
		if (!eating_count(&monitor->philo[i], monitor, &check_num))
			return (0);
		if (ft_get_time() - monitor->philo[i].last_meal > \
			monitor->philo[i].time_die)
		{
			pthread_mutex_lock(monitor->philo[i].alive_lock);
			*(monitor->philo[i].alive) = 0;
			pthread_mutex_unlock(monitor->philo[i].alive_lock);
			print(&monitor->philo[i], dead, ft_get_time() - \
				monitor->philo[i].start_time);
			pthread_mutex_unlock(monitor->philo[i].time_lock);
			return (0);
		}
		pthread_mutex_unlock(monitor->philo[i].time_lock);
		i++;
	}
	return (1);
}

void	*ft_mornitoring(void *arg)
{
	int		i;
	t_table	*monitor;

	monitor = (t_table *)arg;
	while (1)
	{
		i = 0;
		if (monitor->eat_flag == 1)
		{
			print(&monitor->philo[0], complete, ft_get_time() - \
				monitor->philo[i].start_time);
			return (NULL);
		}
		if (!monitoring_sys(monitor) && monitor->eat_flag == 0)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

int	check_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->alive_lock);
	if (*(philo->alive) == 0 || philo->num_philo == 1)
	{
		pthread_mutex_unlock(philo->alive_lock);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(philo->alive_lock);
		return (1);
	}
}
