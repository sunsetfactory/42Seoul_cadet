/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:59:44 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/24 13:56:58 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_free(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
		pthread_join(table->philo[i++].thread, NULL);
	free(table->philo);
	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philo[i].last_meal_lock);
		++i;
	}
	pthread_mutex_destroy(&table->finish_lock);
	pthread_mutex_destroy(&table->all_ate_lock);
	free(table->forks);
	free(table->monitor);
	free(table);
}
