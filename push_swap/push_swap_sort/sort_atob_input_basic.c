/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_atob_input_basic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:33:35 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/14 17:58:21 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	sort_atob_input_three(t_info info)
{
	int	mid;

	if (get_stacklen(info.a) == 3)
	{
		mid = get_mid(info.a, get_stacklen(info.a), info);
		if (!is_sorted(info.a))
		{
			if (info.a->num > mid)
				info = ra(info);
			else if (info.a->next->num > mid)
				info = rra(info);
			if (info.a->num == mid)
				info = sa(info);
		}
	}
	return (info);
}

t_info	sort_atob_input_four(t_info info)
{
	t_stack	*tail;
	int		mid;
	int		min;

	tail = find_tail(info.a);
	mid = get_mid(info.a, get_stacklen(info.a), info);
	min = get_min(info.a, get_stacklen(info.a));
	if (info.a->num < mid
		|| info.a->num == get_max(info.a, get_stacklen(info.a)))
		info = pb(info);
	else if (tail->num < mid || info.a->next->num < mid)
	{
		if (info.a->next->num < mid && tail->num != min)
			info = sa(info);
		else if (tail->num < mid && info.a->next->num != min)
			info = rra(info);
		info = pb(info);
	}
	info = sort_atob_input_three(info);
	info = pa(info);
	if (info.a->num == get_max(info.a, get_stacklen(info.a)))
		info = ra(info);
	else if (info.a->num > info.a->next->num)
		info = sa(info);
	return (info);
}

t_info	fick_and_pb(t_info info, int min, int mid, int max)
{
	t_stack	*tail;

	tail = find_tail(info.a);
	if (info.a->num < mid || info.a->num == max)
		info = pb(info);
	else if (tail->num < mid || info.a->next->num < mid
		|| tail->num == max || info.a->next->num == max)
	{
		if ((info.a->next->num < mid && tail->num != min)
			|| (info.a->next->num == max && tail->num != min))
			info = sa(info);
		else if ((tail->num < mid && info.a->next->num != min)
			|| (tail->num == max && info.a->next->num != min))
			info = rra(info);
		info = pb(info);
	}
	return (info);
}

t_info	sort_atob_input_five(t_info info)
{
	int		mid;
	int		min;
	int		max;

	mid = get_mid(info.a, get_stacklen(info.a), info);
	min = get_min(info.a, get_stacklen(info.a));
	max = get_max(info.a, get_stacklen(info.a));
	info = fick_and_pb(info, min, mid, max);
	info = sort_atob_input_four(info);
	info = pa(info);
	if (info.a->num == max)
		info = ra(info);
	else if (info.a->num > info.a->next->num)
		info = sa(info);
	return (info);
}
