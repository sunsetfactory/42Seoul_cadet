/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:51:28 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 02:05:50 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	not_fork(t_comm *cmd, t_env_d *my_envp, t_data *ofd_arg, t_hdoc *hdoc)
{
	ofd_arg->in_fd = dup(0);
	ofd_arg->out_fd = dup(1);
	if (ft_redirect_handling(cmd, hdoc) != EXIT_SUCCESS)
	{
		dup2(ofd_arg->in_fd, 0);
		dup2(ofd_arg->out_fd, 1);
		return ;
	}
	ofd_arg->args = make_args(cmd, &ofd_arg->arg_cnt);
	if (is_blt(ofd_arg->args))
		exe_cmd(cmd, my_envp, ofd_arg->args, ofd_arg->arg_cnt);
	if ((ofd_arg)->args)
		free((ofd_arg)->args);
	dup2(ofd_arg->in_fd, 0);
	dup2(ofd_arg->out_fd, 1);
}

void	ft_waitpid(t_env_d *my_envp_d, t_data *ofd_arg)
{
	int	i;
	int	status;
	int	signo;

	i = 0;
	while (i < ofd_arg->cmd_count)
	{
		waitpid(ofd_arg->pid[i], &status, 0);
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			update_recent_exit_status(my_envp_d, 128 + signo);
			g_signal = 0;
		}
		else
			update_recent_exit_status(my_envp_d, WEXITSTATUS(status));
		i++;
	}
}

void	use_fork(t_comm *cmd, t_env_d *my_envp, t_data *ofd_arg, t_hdoc *hdoc)
{
	ofd_arg->in_fd = dup(0);
	ofd_arg->out_fd = dup(1);
	ofd_arg->pid = (int *)malloc(sizeof(int) * ofd_arg->cmd_count);
	ofd_arg->i_pid = 0;
	child_process(cmd, my_envp, ofd_arg, hdoc);
	dup2(ofd_arg->in_fd, 0);
	dup2(ofd_arg->out_fd, 1);
	ft_waitpid(my_envp, ofd_arg);
	if (ofd_arg->pid)
		free(ofd_arg->pid);
}
