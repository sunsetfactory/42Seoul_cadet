/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:34:14 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/24 17:35:44 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_mutex(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&table->finish_lock, NULL);
	pthread_mutex_init(&table->all_ate_lock, NULL);
	while (i < table->num_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(&table->philo[i].last_meal_lock, NULL);
		++i;
	}
}

int	ft_check_table(t_table table, int ac)
{
	if (ac == 6 && table.num_must_eat <= 0)
		return (ft_puterr("ERROR: wrong num of must eat\n"));
	if (table.num_philo < 0)
		return (ft_puterr("ERROR: wrong num of philo\n"));
	if (table.time_die < 60)
		return (ft_puterr("ERROR: wrong time to die\n"));
	if (table.time_eat < 60)
		return (ft_puterr("ERROR: wrong time to eat\n"));
	if (table.time_sleep < 60)
		return (ft_puterr("ERROR: wrong time to sleep\n"));
	return (SCS);
}

void	ft_get_args(t_table *table, int ac, char **av)
{
	table->num_philo = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->num_must_eat = ft_atoi(av[5]);
	else
		table->num_must_eat = -1;
}

int	ft_init_all(t_table *table, int ac, char **av)
{
	if (!table)
		return (ERR);
	ft_get_args(table, ac, av);
	if (ft_check_table(*table, ac))
		return (ERR);
	table->philo = ft_calloc(table->num_philo, sizeof(t_philo));
	table->forks = ft_calloc(table->num_philo, sizeof(pthread_mutex_t));
	table->monitor = ft_calloc(table->num_philo + 1, sizeof(pthread_t));
	if (!table->philo || !table->forks || !table->monitor)
		return (ERR);
	table->finish = false;
	table->all_ate = 0;
	ft_init_mutex(table);
	ft_create_philos(table);
	return (SCS);
}
