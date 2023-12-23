/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:17:50 by ael-khni          #+#    #+#             */
/*   Updated: 2023/12/23 19:11:39 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_philo *philo, int f, int c)
{
	pthread_mutex_lock(&philo->table->forks[f]);
	if (c == RIGHT)
		ft_print_msg(philo, "has taken a fork_R");
	if (c == LEFT)
		ft_print_msg(philo, "has taken a fork_L");
}
