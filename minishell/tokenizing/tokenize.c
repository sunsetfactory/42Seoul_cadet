/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:33:37 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 15:34:27 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*mk_strdup(int start, int end, char *line, int flag)
{
	char	*new_line;
	int		i;
	int		j;

	if (start > end)
		return (ft_strdup(""));
	new_line = (char *)malloc(sizeof(char) * (end - start + 2));
	if (new_line == NULL)
		exit(1);
	i = 0;
	j = start;
	while (j <= end)
	{
		if (line[j] == '\0')
			break ;
		if (!is_space(line[j]) && flag == REMOVE)
			new_line[i++] = line[j];
		else if (flag == LEAVE)
			new_line[i++] = line[j];
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	creat_string(char *line, t_comm **cmd, t_range *range, t_env_d *envp)
{
	char	*temp;

	temp = find_del(mk_strdup(range->start, range->i, \
		line, REMOVE), cmd, 0, 0);
	process_env_var(&temp, cmd, envp);
	split_env(&temp, cmd);
	push_back(cmd, temp, STR);
	free(temp);
}

void	split_line(char *line, t_comm **cmd, t_env_d *envp)
{
	t_range	*range;

	range = (t_range *)malloc(sizeof(t_range));
	range->i = 0;
	range->start = 0;
	while (line[range->i])
	{
		if (line[range->i + 1] == '\0' || is_space(line[range->i]))
		{
			creat_string(line, cmd, range, envp);
			range->start = range->i + 1;
		}
		else if (is_squotes(line[range->i]) || is_dquotes(line[range->i]))
			process_in_quotes(line, range, cmd, envp);
		else if (line[range->i] == '#')
		{
			range->i--;
			creat_string(line, cmd, range, envp);
			break ;
		}
		range->i++;
	}
	free(range);
}
