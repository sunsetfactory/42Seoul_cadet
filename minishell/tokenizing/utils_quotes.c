/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:53:52 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/20 22:56:52 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_natural_str(char **temp, t_comm **cmd, t_env_d *envp)
{
	*temp = find_del(*temp, cmd, 0, 0);
	process_env_var(temp, cmd, envp);
}

void	index_update(int *i, int *start, int quote_pos)
{
	*i = quote_pos;
	*start = quote_pos + 1;
}

void	free_var(char **var_value, char **var_name)
{
	free(*var_value);
	free(*var_name);
}

void	free_temp(char **temp, char **quo_str)
{
	free(*temp);
	free(*quo_str);
	temp = NULL;
	quo_str = NULL;
}
