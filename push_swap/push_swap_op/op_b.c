/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:20:51 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 15:23:27 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	sb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
		{
			do_swap(info.b);
			info = input_operations(info, "sb\n");
		}
	}
	return (info);
}

t_info	do_pb(t_info info, t_stack *x)
{
	if (x->next)
	{
		(x->next)->prev = NULL;
		info.a = x->next;
	}
	else
		info.a = NULL;
	if (info.b)
	{
		x->next = info.b;
		info.b->prev = x;
		info.b = x;
	}
	else
	{
		x->next = NULL;
		info.b = x;
	}
	return (info);
}

t_info	pb(t_info info)
{
	if (info.a)
	{
		info = do_pb(info, info.a);
		info = input_operations(info, "pb\n");
	}
	return (info);
}

t_info	rb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
		{
			info.b = do_rx(info.b);
			info = input_operations(info, "rb\n");
		}
	}
	return (info);
}

t_info	rrb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
		{
			info.b = do_rrx(info.b);
			info = input_operations(info, "rrb\n");
		}
	}
	return (info);
}
