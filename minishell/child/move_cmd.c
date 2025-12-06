/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:44:48 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/19 22:34:39 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_comm	*move_cmd(t_comm *cmd)
{
	t_comm	*mv_cmd;

	mv_cmd = cmd;
	while (1)
	{
		if (mv_cmd == NULL || mv_cmd->type == PIPE)
			break ;
		mv_cmd = mv_cmd->next;
	}
	if (mv_cmd != NULL)
		mv_cmd = mv_cmd->next;
	return (mv_cmd);
}
