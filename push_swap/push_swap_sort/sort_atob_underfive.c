/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_atob_underfive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:59:56 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 17:36:22 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	sort_atob_input_underfive(t_info info)
{
	int	len;

	len = get_stacklen(info.a);
	if (is_sorted(info.a))
		return (info);
	else if (len == 5)
		info = sort_atob_input_five(info);
	else if (len == 4)
		info = sort_atob_input_four(info);
	else if (len == 3)
		info = sort_atob_input_three(info);
	else if (len == 2)
		info = sort_atob_two(info);
	return (info);
}

t_info	sort_atob_underfive(t_info info, int len)
{
	if (is_sorted(info.a))
		return (info);
	if (get_stacklen(info.a) <= 5)
		return (sort_atob_input_underfive(info));
	if (len == 5)
		info = sort_atob_five(info, len);
	if (len == 4)
		info = sort_atob_four(info, len);
	if (len == 3)
		info = sort_atob_three(info);
	if (len == 2)
		info = sort_atob_two(info);
	return (info);
}
