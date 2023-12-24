/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:37:33 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/24 13:54:51 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_philos(t_table *table)
{
	int			i;

	i = 0;
	table->creation_time = ft_get_time();
	while (i < table->num_philo)
	{
		table->philo[i].id = i;
		table->philo[i].table = table;
		table->philo[i].last_meal = table->creation_time;
		table->philo[i].flag_err = false;
		table->philo[i].ate = 0;
		pthread_create(&table->philo[i].thread, NULL, philosophers,
			&table->philo[i]);
		pthread_create(&table->monitor[i], NULL, ft_check_death,
			&table->philo[i]);
		pthread_detach(table->monitor[i]);
		++i;
		usleep(100);
	}
	if (table->num_must_eat >= 0)
	{
		pthread_create(&table->monitor[i], NULL, ft_check_hunger, table);
		pthread_detach(table->monitor[i]);
	}
}
