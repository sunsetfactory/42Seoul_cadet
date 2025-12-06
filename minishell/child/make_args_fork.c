/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:16:13 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 02:03:24 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**allocate_args(void)
{
	char	**args;

	args = (char **)malloc(sizeof(char *));
	args[0] = NULL;
	return (args);
}

char	**make_args_fork(t_comm *cmd, int *args_cnt)
{
	char	**args;

	args = allocate_args();
	while (cmd != NULL)
	{
		if (cmd->token == NULL)
		{
			cmd = cmd->next;
			continue ;
		}
		else if (cmd->type == PIPE)
		{
			cmd = cmd->next;
			break ;
		}
		else
		{
			(*args_cnt)++;
			args = put_args(args, cmd->token, *args_cnt);
		}
		if (cmd->next == NULL)
			break ;
		cmd = cmd->next;
	}
	return (args);
}
