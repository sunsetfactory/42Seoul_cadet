/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_btoa_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:45:38 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/13 18:23:40 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	sort_btoa_two(t_info info)
{
	info = pa(info);
	info = pa(info);
	info = sort_atob_two(info);
	return (info);
}

t_info	sort_btoa_three(t_info info, int len)
{
	int	mid;
	int	min;

	mid = get_mid(info.b, 3, info);
	min = get_min(info.b, 3);
	while (find_overmid(info.b, len, mid))
	{
		if (info.b->num != min)
			info = pa(info);
		else
			info = rb(info);
		len--;
	}
	info = sort_atob_two(info);
	if (len == 0)
		info = rrb(info);
	info = pa(info);
	return (info);
}

t_info	back_and_send(t_info info, int len, int min)
{
	int	cnt_rb;

	cnt_rb = 2 - len;
	while (cnt_rb-- > 0)
	{
		if (len == 1 && info.b->num != min)
		{
			info = pa(info);
			len--;
		}
		info = rrb(info);
		len++;
	}
	if (len)
		info = sort_btoa_underfive(info, len);
	return (info);
}

t_info	sort_btoa_four(t_info info, int len)
{
	int	mid;
	int	min;

	mid = get_mid(info.b, 4, info);
	min = get_min(info.b, 4);
	while (find_overmid(info.b, len, mid))
	{
		if (info.b->num >= mid)
			info = pa(info);
		else
			info = rb(info);
		len--;
	}
	info = sort_atob_two(info);
	info = back_and_send(info, len, min);
	return (info);
}

t_info	sort_btoa_five(t_info info, int len)
{
	int	mid;
	int	min;

	mid = get_mid(info.b, 5, info);
	min = get_min(info.b, 5);
	while (find_overmid(info.b, len, mid))
	{
		if (info.b->num >= mid)
			info = pa(info);
		else
			info = rb(info);
		len--;
	}
	info = sort_atob_three(info);
	info = back_and_send(info, len, min);
	return (info);
}
