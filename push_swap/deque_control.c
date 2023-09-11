/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:58:01 by seokjyan          #+#    #+#             */
/*   Updated: 2023/09/12 07:41:13 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_push_swap *info, int value)
{
	while (info->a->front->data)
	{
		if (info->a->front->data == value)
		{
			info->a->front->next->prev = info->a->front;
			info->a->front = info->a->front->next;
		}
	}
}

t_push_swap	*create_info(int ac, char **av)
{
	t_push_swap	*info_for_a;
	int			i;
	int			value;

	info_for_a = NULL;
	i = 1;
	while (i < ac)
	{
		if (ft_is_digit(av[i]) && is_int(av[i]))
		{
			value = ft_atoi(av[i]);
			if (stack_init(info_for_a, value))
				stack_push(&info_for_a, value);
			else
				return (NULL);
		}
		else
			return (NULL);
		++i;
	}
	return (info_for_a);
}