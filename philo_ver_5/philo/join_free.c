/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:59:44 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/23 19:59:50 by seokjyan         ###   ########.fr       */
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
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->finish_lock);
	free(table->forks);
	free(table);
}
