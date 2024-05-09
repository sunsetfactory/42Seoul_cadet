/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:33:47 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/14 20:50:01 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*set_reserve_node(t_stack *new)
{
	t_stack	*nex;

	while (new->prev)
	{
		nex = new;
		new = new->prev;
		new->next = nex;
	}
	return (new);
}

t_stack	*create_node(void)
{
	t_stack	*x;

	x = (t_stack *)malloc(sizeof(t_stack));
	if (!x)
		return (NULL);
	x->num = 0;
	x->prev = NULL;
	x->next = NULL;
	return (x);
}

t_info	av_connect_node(int argc, char **argv)
{
	t_info	info;
	t_stack	*new;
	t_stack	*tmp;
	int		i;

	info = init_info();
	info.argv = argv;
	tmp = NULL;
	i = 0;
	while (i < argc)
	{
		new = create_node();
		if (!new)
		{
			info.err = -1;
			return (info);
		}
		new->num = ft_atoi(argv[i++]);
		new->prev = tmp;
		tmp = new;
	}
	if (new)
		info.a = set_reserve_node(new);
	return (info);
}
