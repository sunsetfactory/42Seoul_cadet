/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_delimited.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:32:15 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/20 16:34:21 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_prev_str(char *token, t_range *range, \
	t_comm **cmd, t_env_d *envp)
{
	char	*new_token;

	new_token = mk_strdup(range->start, range->i - 1, token, REMOVE);
	process_env_var(&new_token, cmd, envp);
	if (new_token[0])
		push_back(cmd, new_token, STR);
	free(new_token);
}

void	distinguishing_redirec(char *new_token, int flag, t_comm **cmd)
{
	if (ft_strchr(new_token, '<') && flag == SINGLE)
		push_back(cmd, new_token, LESS);
	else if (ft_strchr(new_token, '>') && flag == SINGLE)
		push_back(cmd, new_token, GREAT);
	else if (ft_strchr(new_token, '<') && flag == DOUBLE)
		push_back(cmd, new_token, DLESS);
	else if (ft_strchr(new_token, '>') && flag == DOUBLE)
		push_back(cmd, new_token, DGREAT);
}

void	push_back_delimited(char *token, int *index, t_comm **cmd, int *start)
{
	char	*new_token;

	new_token = NULL;
	if (token[*index] == '|')
	{
		new_token = mk_strdup(*index, *index, token, REMOVE);
		push_back(cmd, new_token, PIPE);
		*index += 1;
	}
	else if ((token[*index] == '<' || token[*index] == '>') \
		&& token[*index + 1] == token[*index])
	{
		new_token = mk_strdup(*index, *index + 1, token, REMOVE);
		distinguishing_redirec(new_token, DOUBLE, cmd);
		*index += 2;
	}
	else
	{
		new_token = mk_strdup(*index, *index, token, REMOVE);
		distinguishing_redirec(new_token, SINGLE, cmd);
		*index += 1;
	}
	free(new_token);
	*start = *index;
}

char	*make_token(int start, int i, char *token)
{
	if (i > start)
		return (mk_strdup(start, i - 1, token, REMOVE));
	else
		return (ft_strdup(""));
}

char	*find_del(char *token, t_comm **cmd, int start, t_env_d *envp)
{
	char	*new_token;
	t_range	*r;

	r = allocate_range(0, start);
	while (is_space(token[r->i]))
	{
		r->i++;
		r->start++;
	}
	while (token[r->i])
	{
		if (token[r->i] == '<' || token[r->i] == '>' || token[r->i] == '|')
		{
			if (r->i > r->start)
				process_prev_str(token, r, cmd, envp);
			push_back_delimited(token, &r->i, cmd, &r->start);
		}
		else
			r->i++;
	}
	new_token = make_token(r->start, r->i, token);
	free(r);
	free(token);
	return (new_token);
}
