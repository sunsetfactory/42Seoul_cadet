/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:34:09 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 13:45:04 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_recent_exit_status(t_env_d *my_envp_d, int sign)
{
	my_envp_d->head->state = sign;
}

int	main(int argc, char **argv, char **envp)
{
	t_comm	*cmd;
	t_env_d	*my_envp_d;
	t_data	*ofd_arg;

	control_arg(argc, argv);
	my_envp_d = make_envp(envp);
	ofd_arg = NULL;
	while (1)
	{
		ofd_arg = allocate_ofd_arg(ofd_arg);
		cmd = NULL;
		if (!read_input(&cmd, my_envp_d))
			continue ;
		if (cmd != NULL)
			run_command(cmd, my_envp_d, ofd_arg);
		free_list(&cmd);
	}
	free_envp(my_envp_d);
	return (0);
}
