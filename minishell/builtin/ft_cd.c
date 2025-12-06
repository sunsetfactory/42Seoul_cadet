/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:09 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/20 22:18:34 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(char **args, t_env_d *my_envp)
{
	char	*path;

	if (args[1] == NULL)
		path = ft_get_env(my_envp->data, "HOME");
	else
		path = ft_strdup(args[1]);
	if (chdir(path) == -1)
	{
		my_envp->head->state = 1;
		perror("chdir");
	}
	else
		my_envp->head->state = 0;
	free(path);
	return (0);
}
