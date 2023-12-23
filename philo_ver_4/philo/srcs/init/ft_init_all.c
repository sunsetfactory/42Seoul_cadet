/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:20:44 by ael-khni          #+#    #+#             */
/*   Updated: 2023/12/23 18:08:00 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_info(t_info info, int ac)
{
	if (ac == 6 && info.number_of_times_each_philosopher_must_eat <= 0)
		return (ft_puterr("ERROR: wrong num of must eat\n"));
	if (info.number_of_philosophers < 0)
		return (ft_puterr("ERROR: wrong num of philo\n"));
	if (info.time_to_die < 60)
		return (ft_puterr("ERROR: wrong time to die\n"));
	if (info.time_to_eat < 60)
		return (ft_puterr("ERROR: wrong time to eat\n"));
	if (info.time_to_sleep < 60)
		return (ft_puterr("ERROR: wrong time to sleep\n"));
	return (FT_SUCCESS);
}

void	ft_get_args(t_info *info, int ac, char **av)
{
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		info->number_of_times_each_philosopher_must_eat = -1;
}

int	ft_init_all(t_info *info, int ac, char **av)
{
	if (!info)
		return (FT_FAILURE);
	ft_get_args(info, ac, av);
	if (ft_check_info(*info, ac))
		return (FT_FAILURE);
	info->philo = ft_calloc(info->number_of_philosophers, sizeof(t_philo));
	info->forks = ft_calloc(info->number_of_philosophers,
			sizeof(pthread_mutex_t));
	if (!info->philo || !info->forks)
		return (FT_FAILURE);
	info->finish = false;
	info->all_ate = 0;
	ft_init_mutex(info);
	ft_create_philos(info);
	return (FT_SUCCESS);
}
