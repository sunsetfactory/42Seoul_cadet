/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:41:33 by minkylee          #+#    #+#             */
/*   Updated: 2023/12/25 22:42:34 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
		pthread_join(table->philo_threads[i++], NULL);
	pthread_join(*table->monitor_thread, NULL);
}

void	free_table(t_table *table)
{
	if (table->philo)
		free(table->philo);
	if (table->forks)
		free(table->forks);
	if (table->philo_threads)
		free(table->philo_threads);
	if (table->monitor_thread)
		free(table->monitor_thread);
}

void	clean_up(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->alive_lock);
	pthread_mutex_destroy(&table->time_lock);
	pthread_mutex_destroy(&table->print_lock);
	while (i < table->num_philo)
		pthread_mutex_destroy(&table->forks[i++].mutex);
	free_table(table);
}

void	create_philo(t_table *table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < table->num_philo)
	{
		if (pthread_create(&table->philo_threads[i], \
			NULL, routine, &table->philo[i]) != 0)
		{
			while (j < i)
				pthread_detach(table->philo_threads[j++]);
			clean_up(table);
			return ;
		}
		i++;
	}
	if (pthread_create(table->monitor_thread, NULL, ft_mornitoring, table) != 0)
	{
		while (j < i)
			pthread_detach(table->philo_threads[j++]);
		pthread_detach(*table->monitor_thread);
	}
}
