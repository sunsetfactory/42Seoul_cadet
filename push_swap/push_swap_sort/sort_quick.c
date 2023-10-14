/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:48:40 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/13 20:06:01 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(int *target, int left, int right)
{
	int	i;
	int	j;
	int	tmp;
	int	pivot;

	if (left >= right)
		return ;
	i = left;
	j = right;
	pivot = target[(left + right) / 2];
	while (1)
	{
		while (target[i] < pivot)
			i++;
		while (pivot < target[j])
			j--;
		if (i >= j)
			break ;
		tmp = target[i];
		target[i++] = target[j];
		target[j--] = tmp;
	}
	quick_sort(target, left, i - 1);
	quick_sort(target, j + 1, right);
}

t_info	btoa(t_info info, int len)
{
	int	mid;
	int	a_len;
	int	b_len;

	a_len = (len / 2) + (len % 2);
	b_len = len / 2;
	if (len <= 5)
		info = sort_btoa_underfive(info, len);
	else
	{
		mid = get_mid(info.b, len, info);
		while (len--)
		{
			if (info.b->num >= mid)
				info = pa(info);
			else
				info = rb(info);
		}
		info = sort_main(info, a_len);
		info = sort_btoa_underfive_rrb(info, b_len);
	}
	return (info);
}

t_info	atob(t_info info, int len)
{
	int	mid;
	int	cnt;
	int	i;

	i = len;
	cnt = 0;
	mid = get_mid(info.a, len, info);
	while (find_undermid(info.a, i--, mid))
	{
		if (info.a->num < mid)
			info = pb(info);
		else
		{
			info = ra(info);
			cnt++;
		}
	}
	if (get_stacklen(info.a) > len)
	{
		while (cnt--)
			info = rra(info);
	}
	return (info);
}

t_info	sort_main(t_info info, int len)
{
	int	a_len;
	int	b_len;

	if (is_sorted(info.a))
		return (info);
	if (len > 5)
	{
		a_len = (len / 2) + (len % 2);
		b_len = len / 2;
		info = atob(info, len);
		if (a_len > 5)
			info = sort_main(info, a_len);
		else
			info = sort_atob_underfive(info, a_len);
		info = btoa(info, b_len);
	}
	else
		info = sort_atob_underfive(info, len);
	return (info);
}
