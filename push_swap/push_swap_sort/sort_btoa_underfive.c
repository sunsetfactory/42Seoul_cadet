/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_btoa_underfive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:48:16 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/13 16:54:45 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	re_sort_a_b(t_info info, int a_len, int b_len)
{
	if (a_len > 0 && a_len <= 5)
		info = sort_atob_underfive(info, a_len);
	else if (a_len > 5)
		info = sort_main(info, a_len);
	if (b_len > 0 && b_len <= 5)
		info = sort_btoa_underfive(info, b_len);
	else if (b_len > 5)
		info = btoa(info, b_len);
	return (info);
}

t_info	sort_btoa_underfive_rrb(t_info info, int len)
{
	int	mid;
	int	i;
	int	stack_len;

	i = len;
	stack_len = get_stacklen(info.b);
	// mid = get_mid_from_end(info.b, len, info);
	mid = get_mid_from_end(info.b, len);
	while (stack_len == len && i--)
	{
		if (info.b->num >= mid)
			info = pa(info);
		else
			info = rb(info);
	}
	while (stack_len != len && i--)
	{
		info = rrb(info);
		if (info.b->num >= mid)
			info = pa(info);
	}
	info = re_sort_a_b(info, (len / 2) + (len % 2), (len / 2));
	return (info);
}

t_info	sort_btoa_underfive(t_info info, int len)
{
	int	n;

	n = get_stacklen(info.b);
	if (len > n)
		len = n;
	if (len == 1 && n >= 1)
		info = pa(info);
	else if (len == 2 && n >= 2)
		info = sort_btoa_two(info);
	else if (len == 3 && n >= 3)
		info = sort_btoa_three(info, len);
	else if (len == 4 && n >= 4)
		info = sort_btoa_four(info, len);
	else if (len == 5 && n >= 5)
		info = sort_btoa_five(info, len);
	return (info);
}