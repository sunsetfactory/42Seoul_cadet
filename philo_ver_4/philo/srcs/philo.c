/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:39:54 by ael-khni          #+#    #+#             */
/*   Updated: 2023/12/23 19:05:07 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac != 5 && ac != 6)
		return (ft_puterr("Usage: ./philo <number_of_philos> <time_die> "
				"<time_eat> <time_sleep> "
				"[number_of_times_eacih_philosopher_must_eat]\n"));
	table = ft_calloc(1, sizeof(*table));
	if (ft_init_all(table, ac, av) == SCS)
		ft_join_free(table);
	return (SCS);
}
