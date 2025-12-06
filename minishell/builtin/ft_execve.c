/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:33:47 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/20 22:04:32 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cnt_envp(t_envp *my_envp)
{
	t_envp		*current;
	int			i;

	current = my_envp;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

char	**make_origin_envp(t_envp *my_envp)
{
	int			i;
	char		**origin_envp;
	t_envp		*current;

	i = cnt_envp(my_envp);
	origin_envp = (char **)malloc((i + 1) * sizeof(char *));
	if (origin_envp == NULL)
		return (NULL);
	current = my_envp;
	i = 0;
	while (current != NULL)
	{
		if (current->state == HAS_EQUAL)
		{
			origin_envp[i] = ft_strjoin(current->key, "=");
			origin_envp[i] = ft_strjoin(origin_envp[i], current->value);
		}
		else
			origin_envp[i] = ft_strdup(current->key);
		current = current->next;
		i++;
	}
	origin_envp[i] = NULL;
	return (origin_envp);
}

int	ft_execve(char **args, t_envp *my_envp)
{
	char	*path;
	char	**new_envp;

	path = find_cmd_path(args[0], my_envp);
	if (path == NULL)
		path = args[0];
	new_envp = make_origin_envp(my_envp);
	if (execve(path, args, new_envp) == -1)
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	return (0);
}
