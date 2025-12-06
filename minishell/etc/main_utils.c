/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:20:04 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 02:54:19 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*allocate_ofd_arg(t_data *ofd_arg)
{
	signal(SIGINT, handler_sigint);
	signal(SIGQUIT, SIG_IGN);
	ofd_arg = (t_data *)malloc(sizeof(t_data));
	ofd_arg->arg_cnt = 0;
	return (ofd_arg);
}

void	control_arg(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	g_signal = 0;
	ctl_print_off();
}
