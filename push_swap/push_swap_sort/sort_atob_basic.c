/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_atob_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:12:41 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/13 20:07:59 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	sort_atob_two(t_info info)
{
	if (info.a)
	{
		if (info.a->num > info.a->next->num)
			info = sa(info);
	}
	return (info);
}

t_info	sort_atob_three(t_info info)
{
	int		len;
	t_stack	*tail;

	len = get_stacklen(info.a);
	tail = NULL;
	if (len > 3)
	{
		tail = (info.a->next)->next;
		while (info.a != tail)
		{
			if (info.a->num > (info.a->next)->num)
				info = sa(info);
			info = pb(info);
		}
		if (info.b->num < (info.b->next)->num)
			info = sb(info);
		info = pa(info);
		info = pa(info);
	}
	else if (len == 3)
		info = sort_atob_input_three(info);
	return (info);
}

t_info	rra_and_btoa(t_info info, int cnt_ra, int cnt_pb)
{
	while (cnt_ra--)
		info = rra(info);
	if (info.a->num > info.a->next->num)
		info = sa(info);
	info = sort_btoa_underfive(info, cnt_pb);
	return (info);
}

t_info	sort_atob_four(t_info info, int len)
{
	int	mid;
	int	cnt_pb;

	mid = get_mid(info.a, len, info);
	cnt_pb = 0;
	while (len > 1)
	{
		if (info.a->num < mid)
		{
			info = pb(info);
			cnt_pb++;
			len--;
		}
		else if (4 - len - cnt_pb > 0)
			info = sa(info);
		else
		{
			info = ra(info);
			len--;
		}
	}
	info = rra_and_btoa(info, 4 - len - cnt_pb, cnt_pb);
	return (info);
}

t_info	sort_atob_five(t_info info, int len)
{
	int	mid;
	int	cnt_pb;
	int	cnt_ra;

	mid = get_mid(info.a, len, info);
	cnt_pb = 0;
	cnt_ra = 0;
	while (len--)
	{
		if (info.a->num <= mid)
		{
			info = pb(info);
			cnt_pb++;
		}
		else
		{
			info = ra(info);
			cnt_ra++;
		}
	}
	info = rra_and_btoa(info, cnt_ra, cnt_pb);
	return (info);
}
