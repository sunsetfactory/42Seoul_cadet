/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:29:44 by seokjyan          #+#    #+#             */
/*   Updated: 2023/12/24 20:23:30 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->flag_err_lock);
	if (!philo->table->finish)
		printf("%lli\t%i\t%s\n", ft_current_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->flag_err_lock);
}

int	ft_puterr(char *err)
{
	write(STDERR_FILENO, err, ft_strlen(err));
	return (ERR);
}
