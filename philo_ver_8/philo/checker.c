/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:05:48 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/24 13:20:32 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->table->finish_lock);
	while (!philo->table->finish)
	{
		pthread_mutex_unlock(&philo->table->finish_lock);
		pthread_mutex_lock(&philo->last_meal_lock);
		if ((philo->last_meal + philo->table->time_die) < ft_get_time())
		{
			pthread_mutex_unlock(&philo->last_meal_lock);
			ft_print_msg(philo, "died");
			pthread_mutex_lock(&philo->table->finish_lock);
			philo->flag_err = true;
			philo->table->finish = true;
			pthread_mutex_unlock(&philo->table->finish_lock);
			pthread_mutex_lock(&philo->last_meal_lock);
		}
		pthread_mutex_unlock(&philo->last_meal_lock);
		usleep(500);
		pthread_mutex_lock(&philo->table->finish_lock);
	}
	pthread_mutex_unlock(&philo->table->finish_lock);
	return (NULL);
}

void	*ft_check_hunger(void *arg)
{
	t_table	*table;

	table = arg;
	pthread_mutex_lock(&table->finish_lock);
	while (!table->finish)
	{
		pthread_mutex_unlock(&table->finish_lock);
		pthread_mutex_lock(&table->all_ate_lock);
		if (table->all_ate == table->num_philo)
		{
			pthread_mutex_unlock(&table->all_ate_lock);
			ft_print_msg(table->philo, "all_ate");
			pthread_mutex_lock(&table->finish_lock);
			table->finish = true;
			pthread_mutex_unlock(&table->finish_lock);
			pthread_mutex_lock(&table->all_ate_lock);
		}
		pthread_mutex_unlock(&table->all_ate_lock);
		pthread_mutex_lock(&table->finish_lock);
	}
	pthread_mutex_unlock(&table->finish_lock);
	return (NULL);
}
