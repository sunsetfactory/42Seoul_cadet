/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:00:00 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/14 14:34:32 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_info	info;

	info = init_info();
	info.argv = argv;
	if (err_check(argc, argv) == -1)
		info.err = -1;
	if (info.err == 0)
		info = av_connect_node(argc, argv);
	if (info.err == 0)
		info = sort_main(info, argc);
	if (info.err == 0)
		print_operations(info);
	if (info.err == -1)
		print_error();
	all_free(info);
	return (info.err);
}