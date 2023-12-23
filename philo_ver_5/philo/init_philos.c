/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:37:33 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/23 21:35:48 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->table->finish)
	{
		if ((philo->last_meal + philo->table->time_die) < ft_get_time())
		{
			ft_print_msg(philo, "died");
			philo->should_die = true;
			philo->table->finish = true;
		}
		usleep(500);
	}
	return (NULL);
}

void	*ft_check_hunger(void *arg)
{
	t_table	*table;

	table = arg;
	while (!table->finish)
	{
		if (table->all_ate == table->num_philo)
		{
			ft_print_msg(table->philo, "all_ate");
			table->finish = true;
		}
	}
	return (NULL);
}

void	ft_create_philos(t_table *table)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	table->creation_time = ft_get_time();
	while (i < table->num_philo)
	{
		table->philo[i].id = i;
		table->philo[i].table = table;
		table->philo[i].last_meal = table->creation_time;
		table->philo[i].should_die = false;
		table->philo[i].ate = 0;
		pthread_create(&table->philo[i].thread, NULL, philosophers,
			&table->philo[i]);
		pthread_create(&monitor, NULL, ft_check_death, &table->philo[i]);
		pthread_detach(monitor);
		i++;
		usleep(100);
	}
	if (table->num_must_eat >= 0)
	{
		pthread_create(&monitor, NULL, ft_check_hunger, table);
		pthread_detach(monitor);
	}
}
