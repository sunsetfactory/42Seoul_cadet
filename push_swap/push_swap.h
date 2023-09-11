/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:14:05 by seokjyan          #+#    #+#             */
/*   Updated: 2023/09/12 06:49:04 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.a/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	unsigned int	cnt;
	struct s_node	*front;
	struct s_node	*rear;
}	t_deque;

typedef struct s_push_swap
{
	unsigned int	cnt;
	t_deque			*a;
	t_deque			*b;
}	t_push_swap;

//deque_control.c
int	stack_init(t_push_swap *info, int value);
t_push_swap	*create_stack(int ac, char **av);

//deque_control_util.c
static int	help_atoi(char *str, int *c);
long long	ft_atoll(const char *str);
int	is_int(const char *str);
int	ft_is_digit(const char *str);

#endif