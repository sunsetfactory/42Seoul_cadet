/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:59:22 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 13:11:54 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env_d *my_envp)
{
	t_envp	*head;

	head = my_envp->data;
	while (my_envp->data != NULL)
	{
		if (ft_strcmp(my_envp->data->key, "") != 0)
		{
			if (my_envp->data->state == HAS_EQUAL)
			{
				ft_putstr_fd(my_envp->data->key, 1);
				ft_putstr_fd("=", 1);
				ft_putstr_fd(my_envp->data->value, 1);
				ft_putstr_fd("\n", 1);
			}
		}
		my_envp->data = my_envp->data->next;
	}
	my_envp->data = head;
	my_envp->head->state = 0;
}
