/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:47:23 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/24 12:48:23 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_then_think(t_philo *philo)
{
	ft_print_msg(philo, "is sleeping");
	usleep(philo->table->time_sleep * 1000);
	ft_print_msg(philo, "is thinking");
}

void	down_fork(t_philo *philo, int f1, int f2)
{
	pthread_mutex_unlock(&philo->table->forks[f1]);
	pthread_mutex_unlock(&philo->table->forks[f2]);
}

void	eating(t_philo *philo)
{
	ft_print_msg(philo, "is eating");
	usleep(philo->table->time_eat * 1000);
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->last_meal_lock);
	philo->ate++;
	if (philo->ate == philo->table->num_must_eat)
	{
		pthread_mutex_lock(&philo->table->all_ate_lock);
		philo->table->all_ate++;
		pthread_mutex_unlock(&philo->table->all_ate_lock);
	}
}

void	grab_fork(t_philo *philo, int f, int c)
{
	pthread_mutex_lock(&philo->table->forks[f]);
	if (c == RIGHT)
		ft_print_msg(philo, "has taken a fork_R");
	if (c == LEFT)
		ft_print_msg(philo, "has taken a fork_L");
}

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->finish_lock);
	while (!philo->flag_err && !philo->table->finish)
	{
		pthread_mutex_unlock(&philo->table->finish_lock);
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->table->num_philo;
		grab_fork(philo, right_fork, RIGHT);
		if (philo->table->num_philo == 1)
		{
			usleep(1000000);
			break ;
		}
		grab_fork(philo, left_fork, LEFT);
		eating(philo);
		down_fork(philo, right_fork, left_fork);
		sleep_then_think(philo);
		pthread_mutex_lock(&philo->table->finish_lock);
	}
	pthread_mutex_unlock(&philo->table->finish_lock);
	return (NULL);
}
