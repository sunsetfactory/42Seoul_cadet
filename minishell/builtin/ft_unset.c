/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:40:47 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 13:12:46 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envp	*rm_envp(t_envp *my_envp)
{
	t_envp	*set;

	set = my_envp;
	if (set->state == HAS_EQUAL)
	{
		set->key = "";
		set->value = "";
	}
	else
		set->key = "";
	return (set);
}

void	ft_unset(t_env_d *my_envp, char **args)
{
	t_envp	*head_envp;
	char	*key;
	int		i;

	head_envp = my_envp->data;
	i = 1;
	while (args[i] != NULL)
	{
		key = args[i];
		my_envp->data = head_envp;
		while (my_envp != NULL)
		{
			if (ft_strcmp(my_envp->data->key, key) == 0)
			{
				my_envp->data = rm_envp(my_envp->data);
				break ;
			}
			my_envp->data = my_envp->data->next;
		}
		i++;
	}
	my_envp->data = head_envp;
	my_envp->head->state = 0;
}
