/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:36:27 by minkylee          #+#    #+#             */
/*   Updated: 2023/12/25 22:45:05 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->num_philo == 1)
		return ;
	is_valid_fork(philo);
	if (!check_alive(philo))
		return ;
	pthread_mutex_lock(philo->time_lock);
	philo->last_meal = ft_get_time();
	philo->num_time_each--;
	print(philo, eating, ft_get_time() - philo->start_time);
	pthread_mutex_unlock(philo->time_lock);
	ft_usleep(philo->time_eat);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	*routine(void *argu)
{
	t_philo	*philo;

	philo = (t_philo *)argu;
	if (philo->id % 2 == 1)
		ft_usleep(philo->time_eat);
	while (check_alive(philo) && philo->num_time_each != 0)
	{
		eat(philo);
		if (philo->num_time_each == 0 || !check_alive(philo))
			break ;
		print(philo, sleeping, ft_get_time() - philo->start_time);
		ft_usleep(philo->time_sleep);
		if (!check_alive(philo))
			break ;
		print(philo, thinking, ft_get_time() - philo->start_time);
		usleep(100);
	}
	return (NULL);
}

void	is_valid_fork(t_philo *philo)
{
	philo->right_fork->state = 0;
	philo->left_fork->state = 0;
	while (1)
	{
		if (!philo->right_fork->state && \
			pthread_mutex_lock(&philo->right_fork->mutex) == 0)
			philo->right_fork->state = 1;
		if (philo->right_fork->state && !philo->left_fork->state && \
			pthread_mutex_lock(&philo->left_fork->mutex) == 0)
			philo->left_fork->state = 1;
		if (philo->right_fork->state && philo->left_fork->state)
			break ;
		if (philo->right_fork->state && !philo->left_fork->state)
		{
			pthread_mutex_unlock(&philo->right_fork->mutex);
			philo->right_fork->state = 0;
			usleep(100);
		}
	}
	print(philo, fork, ft_get_time() - philo->start_time);
}
