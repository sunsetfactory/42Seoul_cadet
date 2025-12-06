/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:27:34 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/20 23:13:02 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redirection(char *token)
{
	if (ft_strcmp(token, ">") == 0)
		return (GREAT);
	else if (ft_strcmp(token, ">>") == 0)
		return (DGREAT);
	else if (ft_strcmp(token, "<") == 0)
		return (LESS);
	else if (ft_strcmp(token, "<<") == 0)
		return (DLESS);
	return (0);
}

int	ft_redirect_handling(t_comm *cmd, t_hdoc *hdoc)
{
	int		get_type;

	while (cmd != NULL && cmd->type != PIPE)
	{
		get_type = is_redirection(cmd->token);
		if (get_type != 0)
		{
			if (cmd->next != NULL)
			{
				if (exe_redirection(cmd, hdoc) != EXIT_SUCCESS)
					return (EXIT_FAILURE);
				free(cmd->token);
				free(cmd->next->token);
				cmd->token = NULL;
				cmd->next->token = NULL;
				cmd = cmd->next->next;
			}
			else
				cmd = cmd->next;
		}
		else
			cmd = cmd->next;
	}
	return (EXIT_SUCCESS);
}
