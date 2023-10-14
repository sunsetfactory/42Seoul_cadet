/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_xtox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:07:20 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/14 17:59:33 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stacklen(t_stack *x)
{
	int	i;

	i = 0;
	while (x)
	{
		i++;
		x = x->next;
	}
	return (i);
}

int	get_max(t_stack *x, int len)
{
	t_stack	*max;

	max = x;
	while (x && len--)
	{
		if (x->num > max->num)
			max = x;
		x = x->next;
	}
	return (max->num);
}

int	get_min(t_stack *x, int len)
{
	t_stack	*min;

	if (!x)
		return (0);
	min = x;
	while (x && len--)
	{
		if (x->num < min->num)
			min = x;
		x = x->next;
	}
	return (min->num);
}

int	get_mid(t_stack *x, int len, t_info info)
{
	int	*arr;
	int	mid;

	mid = x->num;
	if (len >= 3)
	{
		arr = (int *)malloc(sizeof(int) * len);
		if (!arr)
		{
			all_free(info);
			print_error();
			exit (1);
		}
		pill_arr(arr, x, len);
		quick_sort(arr, 0, len - 1);
		mid = arr[len / 2];
		free(arr);
	}
	return (mid);
}

int	get_mid_from_end(t_stack *b, int len)
{
	int		*arr;
	int		mid;
	t_stack	*start_stack;
	int		i;

	start_stack = find_tail(b);
	i = len - 1;
	while (i--)
		start_stack = start_stack->prev;
	mid = 0;
	if (len >= 1)
	{
		arr = (int *)malloc(sizeof(int) * len);
		if (!arr)
		{
			print_error();
			exit (1);
		}
		pill_arr(arr, start_stack, len);
		quick_sort(arr, 0, len - 1);
		mid = arr[len / 2];
		free(arr);
	}
	return (mid);
}
