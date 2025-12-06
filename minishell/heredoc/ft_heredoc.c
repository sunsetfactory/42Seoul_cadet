/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:27:08 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 13:39:52 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	read_heredoc(char *file_name, char *delimiter)
{
	char	*input;
	int		file_fd;

	signal(SIGINT, handler_sig_child);
	signal(SIGQUIT, SIG_IGN);
	file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
		exit(1);
	while (1)
	{
		input = readline("> ");
		if (!input)
			handler_sig_child(SIGTERM);
		if (is_delimiter(input, delimiter) == 0)
		{
			free(input);
			break ;
		}
		ft_putendl_fd(input, file_fd);
		free(input);
	}
	close(file_fd);
}

void	repeat_read_heredoc(t_hdoc *hdoc)
{
	int	i;

	while (hdoc != NULL)
	{
		i = 0;
		hdoc->del = hdoc->del_head;
		while (i < hdoc->here_cnt)
		{
			read_heredoc(hdoc->filename, hdoc->del->limit);
			if (hdoc->del->next == NULL)
			{
				hdoc->del = hdoc->del_head;
				break ;
			}
			else
				hdoc->del = hdoc->del->next;
			i++;
		}
		if (hdoc->next == NULL)
			break ;
		hdoc = hdoc->next;
	}
}

void	fork_read_heredoc(t_hdoc *hdoc)
{
	int		status;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		repeat_read_heredoc(hdoc);
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
}

t_hdoc	*ft_heredoc(t_comm *cmd)
{
	t_hdoc	*hdoc;
	t_hdoc	*head_hdoc;

	if (is_heredoc(cmd) == 0)
		return (NULL);
	hdoc = set_hdoc();
	head_hdoc = hdoc;
	hdoc = make_hdoc(cmd, hdoc);
	fork_read_heredoc(hdoc);
	return (head_hdoc);
}
