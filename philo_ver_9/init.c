/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:29:40 by minkylee          #+#    #+#             */
/*   Updated: 2023/12/25 22:42:45 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(int argc, char **argv, t_philo *philo, int id)
{
	philo->id = id;
	philo->num_philo = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->num_time_each = -1;
	philo->last_meal = ft_get_time();
	if (argc == 6)
		philo->num_time_each = ft_atoi(argv[5]);
}

int	malloc_tableul(t_table *table)
{
	int	res[3];

	table->philo = malloc(sizeof(t_philo) * table->num_philo);
	table->philo_threads = malloc(sizeof(pthread_t) * table->num_philo);
	table->monitor_thread = malloc(sizeof(pthread_t));
	if (!table->philo || !table->philo_threads || !table->monitor_thread)
		return (0);
	res[0] = pthread_mutex_init(&table->alive_lock, NULL);
	res[1] = pthread_mutex_init(&table->time_lock, NULL);
	res[2] = pthread_mutex_init(&table->print_lock, NULL);
	if (res[0] != 0 || res[1] != 0 || res[2] != 0)
	{
		clean_up(table);
		return (0);
	}
	return (1);
}

void	init_table(t_table *table, int argc, char **argv)
{
	int		i;
	long	start_time;

	table->num_philo = ft_atoi(argv[1]);
	table->forks = init_forks(table->num_philo);
	if (!table->forks)
		return ;
	if (!malloc_tableul(table))
		return ;
	i = 0;
	table->alive = 1;
	table->eat_flag = 0;
	start_time = ft_get_time();
	while (i < table->num_philo)
	{
		table->philo[i].left_fork = &table->forks[i];
		table->philo[i].right_fork = &table->forks[(i + 1) % table->num_philo];
		init_philo(argc, argv, &table->philo[i], i + 1);
		table->philo[i].alive = &table->alive;
		table->philo[i].alive_lock = &table->alive_lock;
		table->philo[i].time_lock = &table->time_lock;
		table->philo[i].print_lock = &table->print_lock;
		table->philo[i].start_time = start_time;
		i++;
	}
}

t_fork	*init_forks(int num_philo)
{
	t_fork	*forks;
	int		i;
	int		j;
	int		res;

	forks = malloc(sizeof(t_fork) * num_philo);
	if (!forks)
		return (NULL);
	i = 0;
	j = 0;
	while (i < num_philo)
	{
		res = pthread_mutex_init(&forks[i].mutex, NULL);
		if (res != 0)
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
