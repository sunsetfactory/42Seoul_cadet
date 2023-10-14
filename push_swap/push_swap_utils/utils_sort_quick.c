/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_quick.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:58 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/13 19:05:51 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *x)
{
	if (x)
	{
		while (x->next)
		{
			if (x->num > (x->next)->num)
				return (0);
			x = x->next;
		}
	}
	return (1);
}

void	pill_arr(int *arr, t_stack *x, int len)
{
	int	i;

	i = 0;
	while (i < len && x)
	{
		arr[i++] = x->num;
		x = x->next;
	}
}

int	find_undermid(t_stack *stk, int len, int mid)
{
	if (!stk)
		return (0);
	while (len && stk)
	{
		if (stk->num < mid)
			return (1);
		stk = stk->next;
		len--;
	}
	return (0);
}

int	find_overmid(t_stack *stk, int len, int mid)
{
	if (!stk)
		return (0);
	while (len && stk)
	{
		if (stk->num >= mid)
			return (1);
		stk = stk->next;
		len--;
	}
	return (0);
}