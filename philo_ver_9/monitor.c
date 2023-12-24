/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:34:08 by minkylee          #+#    #+#             */
/*   Updated: 2023/11/15 02:53:40 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->alive_mutex);
	if (*(philo->alive) == 0 || philo->num_of_philo == 1)
	{
		pthread_mutex_unlock(philo->alive_mutex);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(philo->alive_mutex);
		return (1);
	}
}

int	eating_count(t_philo *philo, t_simul *monitor, int *check_num)
{
	if (philo->number_of_times_each == 0)
			*check_num += 1;
	if (*check_num == monitor->num_of_philo)
	{
		monitor->eat_flag = 1;
		pthread_mutex_unlock(philo->time_mutex);
		return (0);
	}
	return (1);
}

int	monitoring_sys(t_simul *monitor)
{
	int	i;
	int	check_num;

	i = 0;
	check_num = 0;
	while (i < monitor->num_of_philo)
	{
		pthread_mutex_lock(monitor->philo[i].time_mutex);
		if (!eating_count(&monitor->philo[i], monitor, &check_num))
			return (0);
		if (get_time() - monitor->philo[i].last_meal_time > \
			monitor->philo[i].time_to_die)
		{
			pthread_mutex_lock(monitor->philo[i].alive_mutex);
			*(monitor->philo[i].alive) = 0;
			pthread_mutex_unlock(monitor->philo[i].alive_mutex);
			print(&monitor->philo[i], dead, get_time() - \
				monitor->philo[i].start_time);
			pthread_mutex_unlock(monitor->philo[i].time_mutex);
			return (0);
		}
		pthread_mutex_unlock(monitor->philo[i].time_mutex);
		i++;
	}
	return (1);
}

void	*monitoring_routine(void *arg)
{
	int		i;
	t_simul	*monitor;

	monitor = (t_simul *)arg;
	while (1)
	{
		i = 0;
		if (monitor->eat_flag == 1)
		{
			print(&monitor->philo[0], complete, get_time() - \
				monitor->philo[i].start_time);
			return (NULL);
		}
		if (!monitoring_sys(monitor) && monitor->eat_flag == 0)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
