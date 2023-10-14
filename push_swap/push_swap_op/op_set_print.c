/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_set_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:46 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/14 14:35:44 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	input_operations(t_info info, char *op)
{
	char	*tmp;

	if (!info.op)
		info.op = ft_strdup(op);
	else
	{
		tmp = info.op;
		info.op = ft_strjoin(info.op, op);
		free(tmp);
	}
	if (!info.op)
		info.err = -1;
	return (info);
}

char	*put_operation(char *ptr, char *op, int op_len)
{
	write(1, op, ft_strlen(op));
	return (ptr + (sizeof(char) * op_len));
}

char	*check_duplication_op(char *s)
{
	if (ft_strncmp(s, "sa\nsb\n", 6) == 0 || ft_strncmp(s, "sb\nsa\n", 6) == 0)
		s = put_operation(s, "ss\n", 6);
	else if (ft_strncmp(s, "ra\nrb\n", 6) == 0 || ft_strncmp(s, "rb\nra\n", 6) == 0)
		s = put_operation(s, "rr\n", 6);
	else if (ft_strncmp(s, "rra\nrrb\n", 8) == 0
		|| ft_strncmp(s, "rrb\nrra\n", 8) == 0)
		s = put_operation(s, "rrr\n", 8);
	return (s);
}

char	*check_op(char *s)
{
	if (ft_strncmp(s, "sa\n", 3) == 0)
		s = put_operation(s, "sa\n", 3);
	else if (ft_strncmp(s, "sb\n", 3) == 0)
		s = put_operation(s, "sb\n", 3);
	else if (ft_strncmp(s, "ra\n", 3) == 0)
		s = put_operation(s, "ra\n", 3);
	else if (ft_strncmp(s, "rb\n", 3) == 0)
		s = put_operation(s, "rb\n", 3);
	else if (ft_strncmp(s, "pa\n", 3) == 0)
		s = put_operation(s, "pa\n", 3);
	else if (ft_strncmp(s, "pb\n", 3) == 0)
		s = put_operation(s, "pb\n", 3);
	else if (ft_strncmp(s, "rra\n", 4) == 0)
		s = put_operation(s, "rra\n", 4);
	else if (ft_strncmp(s, "rrb\n", 4) == 0)
		s = put_operation(s, "rrb\n", 4);
	return (s);
}

void	print_operations(t_info info)
{
	char	*s;
	char	*tmp;

	tmp = NULL;
	s = info.op;
	while (s)
	{
		if (!*s)
			break ;
		while (tmp != s)
		{
			tmp = s;
			s = check_duplication_op(s);
		}
		s = check_op(s);
	}
}
