/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:21:11 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 02:44:20 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_ofd_args(t_data **ofd_arg)
{
	int	i;

	i = 0;
	if (!ofd_arg)
		return ;
	free(*ofd_arg);
	*ofd_arg = NULL;
}

void	free_envp(t_env_d *my_env_d)
{
	t_envp	*tmp;

	free (my_env_d->head);
	while (my_env_d->data != NULL)
	{
		tmp = my_env_d->data;
		my_env_d->data = my_env_d->data->next;
		free (tmp->key);
		free (tmp->value);
		free (tmp);
	}
}

void	free_all_hdoc(t_hdoc **hdoc)
{
	t_hdoc	*tmp_h;
	t_del	*tmp_d;

	while ((*hdoc) != NULL)
	{
		tmp_h = (*hdoc);
		while ((*hdoc)->del_head)
		{
			tmp_d = (*hdoc)->del_head;
			(*hdoc)->del_head = (*hdoc)->del_head->next;
			free((tmp_d));
		}
		if (access((*hdoc)->filename, F_OK) == 0)
			unlink((*hdoc)->filename);
		if ((*hdoc)->filename)
			free((*hdoc)->filename);
		(*hdoc)->filename = NULL;
		(*hdoc) = (*hdoc)->next;
		free(tmp_h);
	}
	hdoc = NULL;
}
