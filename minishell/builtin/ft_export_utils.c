/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:05:03 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 01:10:36 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	list_export(t_envp *my_envp)
{
	while (my_envp != NULL)
	{
		if (ft_strcmp(my_envp->key, "") != 0)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(my_envp->key, 1);
			if (my_envp->state == HAS_EQUAL)
			{
				ft_putstr_fd("=", 1);
				ft_putstr_fd("\"", 1);
				ft_putstr_fd(my_envp->value, 1);
				ft_putstr_fd("\"", 1);
			}
			ft_putstr_fd("\n", 1);
		}
		my_envp = my_envp->next;
	}
}

void	modi_export(t_envp *my_envp, char **args, int i_line, int pos)
{
	t_envp	*cp_envp;
	int		i;

	cp_envp = my_envp;
	i = 0;
	while (i < pos)
	{
		cp_envp = cp_envp->next;
		i++;
	}
	if (ft_strcmp(cp_envp->value, "") == 0)
		add_envp(cp_envp, args, i_line);
}

void	add_export(t_envp *my_envp, char **args, int i_line)
{
	t_envp	*cp_envp;

	cp_envp = my_envp;
	while (cp_envp != NULL && cp_envp->next != NULL)
		cp_envp = cp_envp->next;
	cp_envp->next = (t_envp *)malloc(sizeof(t_envp));
	cp_envp = cp_envp->next;
	cp_envp->next = NULL;
	add_envp(cp_envp, args, i_line);
}
