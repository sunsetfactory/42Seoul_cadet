/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:21:50 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 13:55:13 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ctl_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	handler_sigint(int key)
{
	if (key == SIGTERM)
	{
		ft_putstr_fd("\033[1A", 1);
		ft_putstr_fd("\033[13C", 1);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (key == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = SIGINT;
	}
}

void	handler_sigquit(int key)
{
	if (key == SIGQUIT)
	{
		ft_putstr_fd("^\\Quit: 3\n", 1);
	}
	if (key == SIGINT)
	{
		ft_putstr_fd("^C\n", 1);
	}
}

void	handler_sig_child(int key)
{
	if (key == SIGTERM)
	{
		ft_putstr_fd("\033[1A", 1);
		ft_putstr_fd("\033[2C", 1);
		exit(0);
	}
	if (key == SIGINT)
	{
		write(1, "\n", 1);
		exit(1);
	}
}
