/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_synerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:46:49 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/21 16:17:18 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pipe_at_the_end(char *buf)
{
	int	i;

	i = ft_strlen(buf) - 1;
	while (i >= 0 && buf[i] == 'S')
		i--;
	if (i > 0 && buf[i] == 'p')
	{
		if ((i >= 1 && buf[i] == 'p' && buf[i - 1] != 'p'))
			printf("minishell: syntax error near unexpected token `|'\n");
		else if (buf[i - 1] == 'p')
			printf("minishell: syntax error near unexpected token `||'\n");
		return (0);
	}
	else if (i == 0 && buf[i] == 'p')
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int	redirec_at_the_end(char *buf)
{
	int	i;

	i = ft_strlen(buf) - 1;
	while (i >= 0 && buf[i] == 'S')
		i--;
	if (i > 0 && buf[i] == 'r')
	{
		if ((i >= 1 && buf[i] == 'r' && buf[i - 1] != 'r'))
			printf("minishell: syntax error near unexpected token `newline'\n");
		else if (buf[i - 1] == 'r')
			printf("minishell: syntax error near unexpected token `newline'\n");
		return (0);
	}
	else if (i == 0 && buf[i] == 'r')
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (0);
	}
	return (1);
}

int	check_continuous_pipe(char *buf)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (buf[i])
	{
		if (buf[i] != 'p' && buf[i] != 'S')
			flag = 0;
		else if (buf[i] == 'p')
		{
			if (flag == 1)
			{
				printf("minishell: syntax error near unexpected token `|'\n");
				return (0);
			}
			else
				flag = 1;
		}
		i++;
	}
	return (1);
}

int	find_syntax_err(char *buf, t_env_d *envp)
{
	if (pipe_at_the_end(buf) && redirec_at_the_end(buf) \
		&& check_continuous_pipe(buf))
		return (1);
	envp->head->state = SYNTAX_ERR;
	return (0);
}
