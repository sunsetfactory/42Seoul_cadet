/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:38 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 01:59:16 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_parent(int fd[])
{
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}

void	fd_child(int fd[], t_comm *cmd)
{
	close(fd[0]);
	if (cmd != NULL)
		dup2(fd[1], 1);
	close(fd[1]);
}

void	in_parent(t_comm *cmd, t_env_d *my_envp, t_data *ofd_arg, t_hdoc *hdoc)
{
	if (cmd != NULL)
	{
		ofd_arg->i_pid++;
		if (hdoc != NULL && hdoc->next != NULL)
			hdoc = hdoc->next;
		child_process(cmd, my_envp, ofd_arg, hdoc);
	}
}

void	in_child(t_comm *old_cmd, t_env_d *my_envp_d, \
	t_data *ofd_arg, t_hdoc *hdoc)
{
	int	is_exec;

	if (ft_redirect_handling(old_cmd, hdoc) != EXIT_SUCCESS)
		exit(1);
	ofd_arg->arg_cnt = 0;
	ofd_arg->args = make_args_fork(old_cmd, &ofd_arg->arg_cnt);
	is_exec = exe_cmd(old_cmd, my_envp_d, ofd_arg->args, ofd_arg->arg_cnt);
	if (is_exec == 1)
		exit(0);
}

void	child_process(t_comm *cmd, t_env_d *my_envp_d, \
	t_data *ofd_arg, t_hdoc *hdoc)
{
	t_comm	*old_cmd;
	int		fd[2];

	old_cmd = cmd;
	pipe(fd);
	cmd = move_cmd(cmd);
	signal(SIGINT, handler_sigquit);
	signal(SIGQUIT, handler_sigquit);
	ofd_arg->pid[ofd_arg->i_pid] = fork();
	if (ofd_arg->pid[ofd_arg->i_pid] == -1)
	{
		perror("fork");
		return ;
	}
	if (ofd_arg->pid[ofd_arg->i_pid] == 0)
	{
		fd_child(fd, cmd);
		in_child(old_cmd, my_envp_d, ofd_arg, hdoc);
	}
	else
	{
		fd_parent(fd);
		in_parent(cmd, my_envp_d, ofd_arg, hdoc);
	}
}
