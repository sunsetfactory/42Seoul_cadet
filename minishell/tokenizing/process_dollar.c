/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:43:26 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 15:34:57 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	connecting_string(char **token, char *var_value, \
	char *var_name, char *dollar_pos)
{
	char	*new_token;
	char	*temp;
	char	*next_str;

	temp = ft_strjoin(*token, var_value);
	if (return_last_dollar_pos(dollar_pos + 1) != -1)
		next_str = mk_strdup(ft_strlen(var_name) + 1, \
			return_last_dollar_pos(dollar_pos + 1), dollar_pos, LEAVE);
	else
		next_str = mk_strdup(ft_strlen(var_name) + 1, \
			ft_strlen(dollar_pos), dollar_pos, LEAVE);
	new_token = ft_strjoin(temp, next_str);
	free(*token);
	*token = NULL;
	*token = new_token;
	free(next_str);
	free(temp);
}

void	processing_after_dless(char **token)
{
	int	index;
	int	start;

	index = return_last_dollar_pos(*token);
	start = index;
	if ((*token)[index + 1] == '\0')
	{
		free(*token);
		*token = ft_strdup("");
	}
}

void	put_in_env(char **token, char **dollar_pos, t_env_d *envp, t_comm **cmd)
{
	char	*var_name;
	char	*var_value;
	char	*new_dollar_pos;

	new_dollar_pos = NULL;
	var_value = NULL;
	var_name = search_env_name(*dollar_pos + 1);
	if (!check_dless(*cmd))
	{
		push_back(cmd, "$", CONTINUE);
		connecting_string(token, var_name, var_name, *dollar_pos);
		free(var_name);
		return ;
	}
	if (var_name[0] == '?')
		var_value = ft_itoa(envp->head->state);
	else
		var_value = ft_get_env(envp->data, var_name);
	if (var_value)
		connecting_string(token, var_value, var_name, *dollar_pos);
	else
		remove_undefined_env(token);
	free_var(&var_value, &var_name);
}

void	make_prev_str(char **token)
{
	int		i;
	char	*temp;

	i = return_last_dollar_pos(*token);
	temp = mk_strdup(0, i - 1, *token, LEAVE);
	free(*token);
	*token = temp;
}

int	process_env_var(char **token, t_comm **cmd, t_env_d *envp)
{
	char	*dollar_pos;
	char	*temp;

	if (!ft_strchr(*token, '$'))
		return (0);
	dollar_pos = ft_strdup(*token);
	temp = dollar_pos;
	make_prev_str(token);
	while (ft_strchr(dollar_pos, '$'))
	{
		find_last_pos(&dollar_pos);
		put_in_env(token, &dollar_pos, envp, cmd);
		dollar_pos++;
	}
	free(temp);
	return (0);
}
