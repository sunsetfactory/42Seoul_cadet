/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:05 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 02:40:48 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_delimiter(char *input, char *delimiter)
{
	if (!delimiter)
		return (1);
	if (ft_strcmp(input, delimiter) == 0)
		return (0);
	return (1);
}

char	*set_file_name(void)
{
	int		i;
	char	*num;
	char	*tmp;
	char	*file_name;

	i = 0;
	tmp = "tmp";
	while (1)
	{
		num = ft_itoa(i);
		file_name = ft_strjoin(tmp, num);
		free(num);
		if (access(file_name, F_OK) != 0)
			break ;
		free(file_name);
		i++;
	}
	return (file_name);
}

void	more_heredoc(t_hdoc **hdoc, char **tmp)
{
	(*hdoc)->next = set_hdoc();
	(*hdoc) = (*hdoc)->next;
	free(*tmp);
	*tmp = set_file_name();
}

t_hdoc	*make_hdoc(t_comm *cmd, t_hdoc *hdoc)
{
	t_comm	*cp_cmd;
	t_hdoc	*head_hdoc;
	char	*tmp;

	cp_cmd = cmd;
	head_hdoc = hdoc;
	tmp = set_file_name();
	while (cp_cmd != NULL)
	{
		if (cp_cmd->type == DLESS && cp_cmd->next != NULL)
			hdoc = in_hdoc(cp_cmd, hdoc, tmp);
		if (cp_cmd->next == NULL)
			break ;
		if (cp_cmd->next->type == PIPE)
		{
			hdoc->del = hdoc->del_head;
			if (is_more_heredoc(cp_cmd->next) != 0)
				more_heredoc(&hdoc, &tmp);
		}
		cp_cmd = cp_cmd->next;
	}
	hdoc->del = hdoc->del_head;
	free(tmp);
	return (head_hdoc);
}
