/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:05:58 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 15:23:10 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	sa(t_info info)
{
	if (info.a)
	{
		if (info.a->next)
		{
			do_swap(info.a);
			info = input_operations(info, "sa\n");
		}
	}
	return (info);
}

t_info	do_pa(t_info info, t_stack *x)
{
	if (x->next)
	{
		(x->next)->prev = NULL;
		info.b = x->next;
	}
	else
		info.b = NULL;
	if (info.a)
	{
		x->next = info.a;
		info.a->prev = x;
		info.a = x;
	}
	else
	{
		x->next = NULL;
		info.a = x;
	}
	return (info);
}

t_info	pa(t_info info)
{
	if (info.b)
	{
		info = do_pa(info, info.b);
		info = input_operations(info, "pa\n");
	}
	return (info);
}

t_info	ra(t_info info)
{
	if (info.a)
	{
		if (info.a->next)
		{
			info.a = do_rx(info.a);
			info = input_operations(info, "ra\n");
		}
	}
	return (info);
}

t_info	rra(t_info info)
{
	if (info.a)
	{
		if (info.a->next)
		{
			info.a = do_rrx(info.a);
			info = input_operations(info, "rra\n");
		}
	}
	return (info);
}
