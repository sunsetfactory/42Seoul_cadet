/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:55:36 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/14 17:56:49 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				err;
	int				check;
	char			**argv;
	char			*op;
}	t_info;

// error
// err_check.c
int		err_check(int argc, char **argv);
// err_print.c
int		print_error(void);

// free
// free.c
void	all_free(t_info info);

// op
// op_a.c
t_info	sa(t_info info);
t_info	pa(t_info info);
t_info	ra(t_info info);
t_info	rra(t_info info);
// op_b.c
t_info	sb(t_info info);
t_info	pb(t_info info);
t_info	rb(t_info info);
t_info	rrb(t_info info);
// op_base.c
void	do_swap(t_stack *x);
t_stack	*do_rx(t_stack *x);
t_stack	*do_rrx(t_stack *x);
// op_set_print.c
t_info	input_operations(t_info info, char *op);
void	print_operations(t_info info);

// src
// main.c
// push_swap.c

// sort
// sort_quick.c
t_info	sort_main(t_info info, int len);
t_info	btoa(t_info info, int len);
void	quick_sort(int *target, int left, int right);
// sort_atob_underfive.c
t_info	sort_atob_underfive(t_info info, int len);
t_info	sort_atob_input_underfive(t_info info);
// sort_atob_basic.c
t_info	sort_atob_two(t_info info);
t_info	sort_atob_three(t_info info);
t_info	sort_atob_four(t_info info, int len);
t_info	sort_atob_five(t_info info, int len);
// sort_atob_input_basic.c
t_info	sort_atob_input_three(t_info info);
t_info	sort_atob_input_four(t_info info);
t_info	sort_atob_input_five(t_info info);
// sort_btoa_underfive.c
t_info	sort_btoa_underfive(t_info info, int len);
t_info	sort_btoa_underfive_rrb(t_info info, int len);
// sort_btoa_basic.c
t_info	sort_btoa_five(t_info info, int len);
t_info	sort_btoa_four(t_info info, int len);
t_info	sort_btoa_three(t_info info, int len);
t_info	sort_btoa_two(t_info info);

// src
// main.c
// push_swap.c
int		push_swap(int argc, char **argv);

// stack
// set_stack_a.c
t_info	av_connect_node(int argc, char **argv);

// utils
// utils_main.c
char	*free_av(char *arg, char *arr, char *tmp);
int		av_len(char **argv);
// utils_op.c
t_stack	*find_tail(t_stack *x);
// utils_push_swap.c
t_info	init_info(void);
// utils_sort_quick.c
void	pill_arr(int *arr, t_stack *x, int len);
int		find_overmid(t_stack *stk, int len, int mid);
int		find_undermid(t_stack *stk, int len, int mid);
int		is_sorted(t_stack *x);
// utils_sort_xtox.c
int		get_mid_from_end(t_stack *b, int len);
int		get_mid(t_stack *x, int len, t_info info);
int		get_min(t_stack *x, int len);
int		get_max(t_stack *x, int len);
int		get_stacklen(t_stack *x);

#endif