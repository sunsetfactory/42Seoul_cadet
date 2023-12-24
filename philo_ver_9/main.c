/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:47:18 by minkylee          #+#    #+#             */
/*   Updated: 2023/11/15 13:08:10 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, t_print print, long timeline)
{
	pthread_mutex_lock(philo->print_mutex);
	if (check_alive(philo))
	{
		if (print == taken)
		{
			printf("%ld %d has taken a fork\n", timeline, philo->id);
			printf("%ld %d has taken a fork\n", timeline, philo->id);
		}
		if (print == eating)
			printf("\033[0;36m%ld %d is eating\n\033[0m", timeline, philo->id);
		else if (print == sleeping)
			printf("\033[0;35m%ld %d is sleeping\n\033[0m", timeline, philo->id);
		else if (print == thinking)
			printf("\033[0;33m%ld %d is thinking\n\033[0m", timeline, philo->id);
	}
	if (print == dead)
		printf("\033[0;31m%ld %d died\n\033[0m", timeline, philo->id);
	if (print == complete)
		printf("\033[0;32mEveryone is Full\033[0m");
	pthread_mutex_unlock(philo->print_mutex);
}

int	main(int argc, char **argv)
{
	t_simul	sim;

	if (argc != 5 && argc != 6)
		return (1);
	if (!check_argu(argc, argv))
	{
		printf("Invalid numeric entry\n");
		return (1);
	}
	init_simul(&sim, argc, argv);
	create_philosophers(&sim);
	join_philosophers(&sim);
	clean_up(&sim);
	return (0);
}
