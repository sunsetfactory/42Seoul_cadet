/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:41:33 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 02:44:38 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_str(char *args)
{
	if (args == NULL)
		return (0);
	if (ft_strncmp(args, "cd", 2) == 0)
		return (1);
	if (ft_strncmp(args, "echo", 4) == 0)
		return (1);
	if (ft_strncmp(args, "env", 3) == 0)
		return (1);
	if (ft_strncmp(args, "exit", 4) == 0)
		return (1);
	if (ft_strncmp(args, "export", 6) == 0)
		return (1);
	if (ft_strncmp(args, "pwd", 3) == 0)
		return (1);
	if (ft_strncmp(args, "unset", 5) == 0)
		return (1);
	return (0);
}

static int	is_builtin(t_comm *cmd)
{
	t_comm	*cp_cmd;

	cp_cmd = cmd;
	while (cp_cmd != NULL)
	{
		if (cp_cmd->type == STR)
		{
			if (check_str(cp_cmd->token) == 1)
				return (1);
			break ;
		}
		cp_cmd = cp_cmd->next;
	}
	return (0);
}

static int	is_pip(t_comm *cmd)
{
	t_comm	*cp_cmd;
	int		cmd_cnt;

	cp_cmd = cmd;
	cmd_cnt = 1;
	while (cp_cmd != NULL)
	{
		if (cp_cmd->type == PIPE)
			cmd_cnt++;
		cp_cmd = cp_cmd->next;
	}
	return (cmd_cnt);
}

void	run_command(t_comm *cmd, t_env_d *my_envp_d, t_data *ofd_arg)
{
	int		builtin;
	t_hdoc	*hdoc;

	hdoc = ft_heredoc(cmd);
	builtin = is_builtin(cmd);
	ofd_arg->cmd_count = is_pip(cmd);
	if ((builtin == 1 && ofd_arg->cmd_count == 1))
		not_fork(cmd, my_envp_d, ofd_arg, hdoc);
	else
		use_fork(cmd, my_envp_d, ofd_arg, hdoc);
	free_all_hdoc(&hdoc);
	free_ofd_args(&ofd_arg);
}
