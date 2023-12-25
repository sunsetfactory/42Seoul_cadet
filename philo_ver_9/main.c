/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:47:18 by minkylee          #+#    #+#             */
/*   Updated: 2023/12/25 22:45:20 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, t_print print, long timeline)
{
	pthread_mutex_lock(philo->print_lock);
	if (check_alive(philo))
	{
		if (print == fork)
		{
			printf("%ld %d has taken a fork\n", timeline, philo->id);
			printf("%ld %d has taken a fork\n", timeline, philo->id);
		}
		if (print == eating)
			printf("\033[0;33m%ld %d is eating\n\033[0m", timeline, philo->id);
		else if (print == sleeping)
			printf("\033[0;36m%ld %d is sleeping\n\033[0m", timeline, philo->id);
		else if (print == thinking)
			printf("\033[0;35m%ld %d is thinking\n\033[0m", timeline, philo->id);
	}
	if (print == dead)
		printf("\033[0;32m%ld %d died\n\033[0m", timeline, philo->id);
	if (print == complete)
		printf("\033[0;31mall_ate\033[0m");
	pthread_mutex_unlock(philo->print_lock);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (1);
	if (!check_argu(argc, argv))
	{
		printf("invalid argument\n");
		return (1);
	}
	init_table(&table, argc, argv);
	create_philo(&table);
	join_philo(&table);
	clean_up(&table);
	return (0);
}
