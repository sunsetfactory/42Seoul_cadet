/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:09:05 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/20 00:09:05 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// arg parsing init
// mtx init
// ate _all cnt check
// make philo
	// rutine

void	*checker_death(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	i = 0;
	while (1)
	{
		// pthread_mutex_lock(&philo->eat_mtx);
		pthread_mutex_lock(&table->death);
		// pthread_mutex_lock(&philo->state_mtx);
		if (table->state == RUN)
		{
			if (get_present_time() > table->philo_arr[i].death_time)
			{
				msg_print(END_STARV, &table->philo_arr[i]);
				pthread_mutex_unlock(&table->death);
				// pthread_mutex_unlock(&philo->state_mtx);
				// pthread_mutex_unlock(&philo->eat_mtx);
				pthread_mutex_unlock(&table->main_mtx);
				return (NULL);
			}
		}
		// pthread_mutex_unlock(&philo->state_mtx);
		pthread_mutex_unlock(&table->death);
		// pthread_mutex_unlock(&philo->eat_mtx);
		usleep(1000);
	}
}

void	*checker_cnt(void *data)
{
	t_table	*table;
	int		i;
	int		cnt;

	table = (t_table *)data;
	i = 0;
	cnt = 0;
	while (1)
	{
		pthread_mutex_lock(&table->philo_arr[i].eat_mtx);
		if (table->philo_arr[i].cnt_eat >= table->num_must_eat && \
		table->philo_arr[i].all_ate == 0)
		{
		// 	pthread_mutex_lock(&table->philo_arr[i].eat_mtx);
			table->philo_arr[i].all_ate = 1;
			++cnt;
		}
		pthread_mutex_unlock(&table->philo_arr[i].eat_mtx);
		if (cnt >= table->num_philo)
			break ;
		if (++i >= table->num_philo)
			i = 0;
	}
	msg_print(END_COUNT, &table->philo_arr[0]);
	pthread_mutex_lock(&table->msg_mtx);
	pthread_mutex_unlock(&table->main_mtx);
	return (NULL);
}
