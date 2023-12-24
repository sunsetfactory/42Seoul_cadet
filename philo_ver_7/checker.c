/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:05:48 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/24 20:47:20 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_check_death(void *arg)
{
	t_table *table;
	int i;
	int cnt;

	table = arg;
	i = 0;
	cnt = 0;
	while (1)
	{
		pthread_mutex_lock(&table->philo->last_meal_lock);
		if ((table->philo[i].last_meal + table->time_die) < ft_get_time())
		{
			pthread_mutex_unlock(&table->philo->last_meal_lock);
			ft_print_msg(table->philo, "died");
			pthread_mutex_lock(&table->philo[i].flag_err_lock);
			// table->philo[i].flag_err = true;
			table->finish = true;
			pthread_mutex_unlock(&table->philo[i].flag_err_lock);
			break;
		}
		pthread_mutex_unlock(&table->philo->last_meal_lock);
		if (++i >= table->num_philo)
			i = 0;
		ft_usleep(100);
		if (table->num_must_eat >= 0)
		{
			pthread_mutex_lock(&table->all_ate_lock);
			if (table->all_ate >= table->num_philo)
			{
				pthread_mutex_unlock(&table->all_ate_lock);
				ft_print_msg(table->philo, "all_ate");
				pthread_mutex_lock(&table->philo->flag_err_lock);
				table->finish = true;
				pthread_mutex_unlock(&table->philo->flag_err_lock);
				break;
			}
		}
		pthread_mutex_unlock(&table->all_ate_lock);
	}
	return (NULL);
}
