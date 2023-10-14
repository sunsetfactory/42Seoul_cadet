/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:47:03 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/14 17:57:59 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_free(t_stack *x)
{
	t_stack	*tmp;

	tmp = NULL;
	while (x)
	{
		tmp = x->next;
		free(x);
		x = tmp;
	}
}

void	all_free(t_info info)
{
	int	i;

	if (info.a)
		stack_free(info.a);
	if (info.b)
		stack_free(info.b);
	if (info.op)
		free(info.op);
	i = 0;
	if (info.argv)
	{
		while (info.argv[i])
		{
			free(info.argv[i]);
			i++;
		}
	}
}
