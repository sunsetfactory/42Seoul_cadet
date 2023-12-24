/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:41:33 by minkylee          #+#    #+#             */
/*   Updated: 2023/11/15 13:06:21 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philosophers(t_simul *sim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sim->num_of_philo)
	{
		if (pthread_create(&sim->philo_threads[i], \
			NULL, routine, &sim->philo[i]) != 0)
		{
			while (j < i)
				pthread_detach(sim->philo_threads[j++]);
			clean_up(sim);
			return ;
		}
		i++;
	}
	if (pthread_create(sim->monitor_thread, NULL, monitoring_routine, sim) != 0)
	{
		while (j < i)
			pthread_detach(sim->philo_threads[j++]);
		pthread_detach(*sim->monitor_thread);
	}
}

void	join_philosophers(t_simul *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philo)
		pthread_join(sim->philo_threads[i++], NULL);
	pthread_join(*sim->monitor_thread, NULL);
}

void	free_sim(t_simul *sim)
{
	if (sim->philo)
		free(sim->philo);
	if (sim->forks)
		free(sim->forks);
	if (sim->philo_threads)
		free(sim->philo_threads);
	if (sim->monitor_thread)
		free(sim->monitor_thread);
}

void	clean_up(t_simul *sim)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&sim->alive_mutex);
	pthread_mutex_destroy(&sim->time_mutex);
	pthread_mutex_destroy(&sim->print_mutex);
	while (i < sim->num_of_philo)
		pthread_mutex_destroy(&sim->forks[i++].mutex);
	free_sim(sim);
}
