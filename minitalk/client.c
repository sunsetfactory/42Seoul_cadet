/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:05:25 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/15 02:44:53 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *msg)
{
	int	bit;
	int	len;

	if (pid < 0 || pid > 32767)
		ft_putstr_fd("invalid PID value\n", 1);
	bit = 128;
	len = ft_strlen(msg);
	while (len >= 0)
	{
		if (*msg & bit)
			kill(pid, SIGUSR1); 
		else
			kill(pid, SIGUSR2);
		bit >>= 1;
		if (bit == 0)
		{
			len--;
			msg++;
			bit = 128;
		}
		usleep(100);
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("./client [server_pid] [\"msg\"]\n", 1);
		return (0);
	}
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
