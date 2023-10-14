/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:00:44 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 14:03:02 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	init_info(void)
{
	t_info	info;

	info.err = 0;
	info.check = 0;
	info.op = NULL;
	info.a = NULL;
	info.b = NULL;
	return (info);
}
