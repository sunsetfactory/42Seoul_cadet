/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:36:07 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 01:04:12 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_echo(char **args, int i_line)
{
	while (args[i_line] != NULL)
	{
		ft_putstr_fd(args[i_line], 1);
		i_line++;
		if (args[i_line] != NULL)
			ft_putstr_fd(" ", 1);
	}
	return (i_line);
}

void	ft_echo(char **args, t_env_d *my_envp)
{
	int	i_line;
	int	i_word;
	int	n_flag;

	i_line = 1;
	n_flag = 0;
	while (args[i_line] != NULL && ft_strncmp(args[i_line], "-", 1) == 0)
	{
		i_word = 1;
		while (args[i_line][i_word] != '\0' && args[i_line][i_word] == 'n')
			i_word++;
		if (args[i_line][i_word] == '\0')
		{
			n_flag = 1;
			i_line++;
		}
		else
			break ;
	}
	i_line = print_echo(args, i_line);
	if (n_flag == 0)
		ft_putstr_fd("\n", 1);
	my_envp->head->state = 0;
}
