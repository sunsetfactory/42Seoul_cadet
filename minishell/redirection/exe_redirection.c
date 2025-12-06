/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:56:32 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/20 23:12:55 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_redirection_out(char *arg, int type)
{
	int	fd;

	if (type == GREAT)
	{
		fd = open(arg, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open");
			return (EXIT_FAILURE);
		}
	}
	else
	{
		fd = open(arg, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("open");
			return (EXIT_FAILURE);
		}
	}
	dup2(fd, 1);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_redirection_in(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		close(fd);
		return (EXIT_FAILURE);
	}
	if (fd == -1)
		return (EXIT_FAILURE);
	dup2(fd, 0);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_here_document(t_hdoc *hdoc)
{
	int	fd;

	fd = open(hdoc->filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		close(fd);
		return (EXIT_FAILURE);
	}
	dup2(fd, 0);
	close(fd);
	return (EXIT_SUCCESS);
}

int	exe_redirection(t_comm *cmd, t_hdoc *hdoc)
{
	if (cmd->type == GREAT || cmd->type == DGREAT)
		return (ft_redirection_out(cmd->next->token, cmd->type));
	if (cmd->type == LESS)
		return (ft_redirection_in(cmd->next->token));
	if (cmd->type == DLESS)
	{
		if (hdoc->here_cnt == 1)
			return (ft_here_document(hdoc));
		else
			(hdoc->here_cnt)--;
	}
	return (EXIT_SUCCESS);
}
