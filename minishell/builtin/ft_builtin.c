/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:49:29 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/20 22:26:06 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exe_cmd(t_comm *cmd, t_env_d *my_envp, char **args, int args_cnt)
{
	if (args[0] == NULL)
		return (1);
	if (ft_strncmp(args[0], "cd", 2) == 0)
		ft_cd(args, my_envp);
	else if (ft_strncmp(args[0], "echo", 4) == 0)
		ft_echo(args, my_envp);
	else if (ft_strncmp(args[0], "env", 3) == 0)
		ft_env(my_envp);
	else if (ft_strncmp(args[0], "exit", 4) == 0)
		ft_exit(cmd, args);
	else if (ft_strncmp(args[0], "export", 6) == 0)
		ft_export(my_envp, args, args_cnt);
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(args[0], "unset", 5) == 0)
		ft_unset(my_envp, args);
	else
	{
		ft_execve(args, my_envp->data);
		return (0);
	}
	return (1);
}

int	is_blt(char **args)
{
	if (args[0] == NULL)
		return (0);
	if (ft_strncmp(args[0], "cd", 2) == 0)
		return (1);
	if (ft_strncmp(args[0], "echo", 4) == 0)
		return (1);
	if (ft_strncmp(args[0], "env", 3) == 0)
		return (1);
	if (ft_strncmp(args[0], "exit", 4) == 0)
		return (1);
	if (ft_strncmp(args[0], "export", 6) == 0)
		return (1);
	if (ft_strncmp(args[0], "pwd", 3) == 0)
		return (1);
	if (ft_strncmp(args[0], "unset", 5) == 0)
		return (1);
	return (0);
}
