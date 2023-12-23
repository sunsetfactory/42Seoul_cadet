/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:17:03 by bguillau          #+#    #+#             */
/*   Updated: 2023/12/23 17:12:34 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	a(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_philo			**philo;
	t_data			*data;

	atexit(a);
	if (argc == 6 && ft_atoi_noverflw(argv[5]) == 0)
		return (0);
	data = arg_to_data(argc, ++argv);
	if (!data)
		return (1);
	philo = init_philo(data);
	if (!philo)
		return (end_free(philo, data), 1);
	simulator(philo, argc);
	return (end_free(philo, data), 0);
}
