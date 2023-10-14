/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:30:58 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/15 02:50:58 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int num)
{
	static char	c = 0;
	static int	bit = 128;

	if (num == SIGUSR1)
		c += bit; 
	bit >>= 1;
	if (bit == 0)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		c = 0;
		bit = 128;
	}
	return ;
}

int		main(void)
{
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	ft_putstr_fd("getpid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
