/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:28 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 14:29:35 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_rtn(int *arr)
{
	free(arr);
	return (-1);
}

int	err_is_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	err_is_not_int(int argc, char **argv)
{
	int			i;
	long long	val;

	i = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 9)
		{
			val = ft_atoi(argv[i]);
			if (val > 2147483647 || val < -2147483648)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	err_is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	int	val;
	int	*arr;
	int	index;

	arr = ft_calloc(sizeof(int), argc);
	if (!arr)
		return (-1);
	i = 0;
	index = 0;
	while (i < argc)
	{
		val = ft_atoi(argv[i++]);
		j = 0;
		while (j < index)
		{
			if (arr[j++] == val)
				return (error_rtn(arr));
		}
		arr[index++] = val;
	}
	free(arr);
	return (0);
}


int	err_check(int argc, char **argv)
{
	int	err;

	err = 0;
	if (err_is_digit(argc, argv) == -1)
		err = -1;
	if (err_is_not_int(argc, argv) == -1)
		err = -1;
	if (err_is_duplicate(argc, argv) == -1)
		err = -1;
	return (err);
}
