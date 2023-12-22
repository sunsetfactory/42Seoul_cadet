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

// void	*checker_death(void *data)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)data;
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philo->eat_mtx);
// 		pthread_mutex_lock(&philo->table->state_mtx);
// 		if (philo->table->state == RUN
// 			&& get_present_time() > philo->death_time)
// 		{
// 			pthread_mutex_unlock(&philo->table->state_mtx);
// 			msg_print(END_STARV, philo);
// 			pthread_mutex_unlock(&philo->table->main_mtx);
// 			return (NULL);
// 		}
// 		pthread_mutex_unlock(&philo->table->state_mtx);
// 		pthread_mutex_unlock(&philo->eat_mtx);
// 		usleep(1000);
// 	}
// }

// void	*checker_death(void *data)
// {
// 	t_table	*table;
// 	int		i;
// 	int		cnt;

// 	table = (t_table *)data;
// 	i = 0;
// 	cnt = 0;
// 	while (1)
// 	{
// 		pthread_mutex_lock(&table->philo_arr[i].eat_mtx);
// 		pthread_mutex_lock(&table->state_mtx);
// 		if (table->state == RUN)
// 		{
// 			pthread_mutex_unlock(&table->state_mtx);
// 			if (get_present_time() > table->philo_arr[i].death_time)
// 			{
// 				msg_print(END_STARV, &table->philo_arr[i]);
// 				pthread_mutex_unlock(&table->main_mtx);
// 				return (NULL);
// 			}
// 		}
// 		pthread_mutex_unlock(&table->state_mtx);
// 		usleep(1000);
// 		pthread_mutex_unlock(&table->philo_arr[i].eat_mtx);
// 		if (cnt >= table->num_philo)
// 			break ;
// 		if (++i >= table->num_philo)
// 			i = 0;
// 	}
// 	return (NULL);
// }


void	*checker_death(void *data)
{
	t_table	*table;
	int		i;
	int		cnt;

	table = (t_table *)data;
	i = 0;
	cnt = 0;
	while (1)
	{
		printf("im alive\n");
		pthread_mutex_lock(&table->state_mtx);
		if (table->state == RUN)
		{
			pthread_mutex_unlock(&table->state_mtx);
			if (get_present_time() > table->philo_arr[i].death_time)
			{
				printf("im die\n");
				pthread_mutex_unlock(&table->main_mtx);
				return (NULL);
			}
		}
		pthread_mutex_unlock(&table->state_mtx);
		if (i > table->num_philo)
			break ;
	}
	return ;
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
		if (table->philo_arr[i].cnt_eat >= table->num_must_eat && \
		table->philo_arr[i].all_ate == 0)
		{
			pthread_mutex_lock(&table->philo_arr[i].eat_mtx);
			table->philo_arr[i].all_ate = 1;
			++cnt;
		}
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
