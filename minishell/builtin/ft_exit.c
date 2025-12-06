/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:54:46 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/21 16:38:49 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_num(char *args)
{
	int	i;

	i = 0;
	while (args[i] != '\0')
	{
		if (ft_isdigit(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_comm *cmd, char **args)
{
	int	errnom;

	if (args[1] != NULL)
		errnom = ft_atoi(args[1]);
	else
		errnom = 0;
	if (args[1] != NULL && check_num(args[1]) == 0)
		errnom = 255;
	if (errnom == -1)
		errnom = 1;
	ft_putstr_fd("exit\n", 1);
	free_list(&cmd);
	exit(errnom);
}
