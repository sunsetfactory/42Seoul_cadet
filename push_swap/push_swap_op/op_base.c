/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:22:34 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 15:23:14 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_stack *x)
{
	int	i;

	if (x)
	{
		if (x->next)
		{
			i = x->num;
			x->num = (x->next)->num;
			(x->next)->num = i;
		}
	}
}

t_stack	*do_rx(t_stack *x)
{
	t_stack	*tail;
	t_stack	*head;

	head = x->next;
	head->prev = NULL;
	tail = find_tail(x);
	tail->next = x;
	x->prev = tail;
	x->next = NULL;
	return (head);
}

t_stack	*do_rrx(t_stack *x)
{
	t_stack	*tail;
	t_stack	*head;

	tail = find_tail(x);
	(tail->prev)->next = NULL;
	head = tail;
	head->prev = NULL;
	head->next = x;
	x->prev = head;
	return (head);
}
