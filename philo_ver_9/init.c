/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:29:40 by minkylee          #+#    #+#             */
/*   Updated: 2023/11/15 13:05:40 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*init_forks(int num_of_philo)
{
	t_fork	*forks;
	int		i;
	int		j;
	int		result;

	forks = malloc(sizeof(t_fork) * num_of_philo);
	if (!forks)
		return (NULL);
	i = 0;
	j = 0;
	while (i < num_of_philo)
	{
		result = pthread_mutex_init(&forks[i].mutex, NULL);
		if (result != 0)
		{
			while (j < i)
				pthread_mutex_destroy(&forks[j++].mutex);
			return (NULL);
		}
		forks[i].id = i + 1;
		forks[i].state = 0;
		i++;
	}
	return (forks);
}

void	init_philo(int argc, char **argv, t_philo *philo, int id)
{
	philo->id = id;
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->number_of_times_each = -1;
	philo->last_meal_time = get_time();
	if (argc == 6)
		philo->number_of_times_each = ft_atoi(argv[5]);
}

int	malloc_simul(t_simul *sim)
{
	int	result[3];

	sim->philo = malloc(sizeof(t_philo) * sim->num_of_philo);
	sim->philo_threads = malloc(sizeof(pthread_t) * sim->num_of_philo);
	sim->monitor_thread = malloc(sizeof(pthread_t));
	if (!sim->philo || !sim->philo_threads || !sim->monitor_thread)
		return (0);
	result[0] = pthread_mutex_init(&sim->alive_mutex, NULL);
	result[1] = pthread_mutex_init(&sim->time_mutex, NULL);
	result[2] = pthread_mutex_init(&sim->print_mutex, NULL);
	if (result[0] != 0 || result[1] != 0 || result[2] != 0)
	{
		clean_up(sim);
		return (0);
	}
	return (1);
}

void	init_simul(t_simul *sim, int argc, char **argv)
{
	int		i;
	long	start_time;

	sim->num_of_philo = ft_atoi(argv[1]);
	sim->forks = init_forks(sim->num_of_philo);
	if (!sim->forks)
		return ;
	if (!malloc_simul(sim))
		return ;
	i = 0;
	sim->alive = 1;
	sim->eat_flag = 0;
	start_time = get_time();
	while (i < sim->num_of_philo)
	{
		sim->philo[i].left_fork = &sim->forks[i];
		sim->philo[i].right_fork = &sim->forks[(i + 1) % sim->num_of_philo];
		init_philo(argc, argv, &sim->philo[i], i + 1);
		sim->philo[i].alive = &sim->alive;
		sim->philo[i].alive_mutex = &sim->alive_mutex;
		sim->philo[i].time_mutex = &sim->time_mutex;
		sim->philo[i].print_mutex = &sim->print_mutex;
		sim->philo[i].start_time = start_time;
		i++;
	}
}
