/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:11 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 13:58:25 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	av_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	*free_av(char *arg, char *av, char *tmp)
{
	free(arg);
	free(av);
	return (tmp);
}