/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:07:57 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 02:40:45 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_more_heredoc(t_comm *cmd)
{
	t_comm	*cp_cmd;
	int		cnt;

	cp_cmd = cmd;
	cnt = 0;
	if (cp_cmd != NULL && cp_cmd->next != NULL)
		cp_cmd = cp_cmd->next;
	while (cp_cmd != NULL && cp_cmd->type != PIPE)
	{
		if (cp_cmd->type == DLESS)
			cnt++;
		if (cp_cmd->next == NULL)
			break ;
		cp_cmd = cp_cmd->next;
	}
	return (cnt);
}

t_hdoc	*in_hdoc(t_comm *cmd, t_hdoc *hdoc, char *tmp)
{
	t_comm	*cp_cmd;
	t_hdoc	*cp_hdoc;

	cp_cmd = cmd;
	cp_hdoc = hdoc;
	cp_hdoc->here_cnt++;
	if (cp_hdoc->here_cnt == 1)
		cp_hdoc->filename = ft_strdup(tmp);
	cp_hdoc->fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cp_hdoc->fd == -1)
		perror("open");
	close(cp_hdoc->fd);
	cp_hdoc->del->limit = cp_cmd->next->token;
	if (cp_hdoc->del_head == NULL)
		cp_hdoc->del_head = cp_hdoc->del;
	cp_hdoc->del->next = (t_del *)malloc(sizeof(t_del));
	cp_hdoc->del = cp_hdoc->del->next;
	cp_hdoc->del->next = NULL;
	return (cp_hdoc);
}

t_hdoc	*set_hdoc(void)
{
	t_hdoc	*new_hdoc;

	new_hdoc = (t_hdoc *)malloc(sizeof(t_hdoc));
	if (new_hdoc == NULL)
		return (NULL);
	new_hdoc->filename = NULL;
	new_hdoc->next = NULL;
	new_hdoc->here_cnt = 0;
	new_hdoc->del = (t_del *)malloc(sizeof(t_del));
	new_hdoc->del_head = NULL;
	return (new_hdoc);
}

int	is_heredoc(t_comm *cmd)
{
	t_comm	*cp_cmd;
	int		cnt;

	cp_cmd = cmd;
	cnt = 0;
	while (cp_cmd != NULL)
	{
		if (cp_cmd->type == DLESS)
			cnt++;
		if (cp_cmd->next == NULL)
			break ;
		cp_cmd = cp_cmd->next;
	}
	return (cnt);
}
