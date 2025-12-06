/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:40:07 by minkylee          #+#    #+#             */
/*   Updated: 2024/01/19 17:21:27 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_pipe(char a)
{
	if (a == '|')
		return (1);
	return (0);
}

int	is_env(char a)
{
	if (a == '$')
		return (1);
	return (0);
}

t_range	*allocate_range(int index, int start)
{
	t_range	*range;

	range = malloc(sizeof(t_range));
	range->i = index;
	range->start = start;
	return (range);
}
