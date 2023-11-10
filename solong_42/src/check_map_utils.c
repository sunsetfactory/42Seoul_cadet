/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:36:52 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/10 19:06:50 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	dfs(t_game *copy, int *count, char find_char);

static void	call_dfs(t_game *copy, int *count, char find_char)
{
	int	x;
	int	y;

	x = copy->player.col1;
	y = copy->player.row1;
	copy->player.row1 = y - 1;
	dfs(copy, count, find_char);
	copy->player.row1 = y;
	copy->player.col1 = x + 1;
	dfs(copy, count, find_char);
	copy->player.col1 = x;
	copy->player.row1 = y + 1;
	dfs(copy, count, find_char);
	copy->player.row1 = y;
	copy->player.col1 = x - 1;
	dfs(copy, count, find_char);
	copy->player.col1 = x;
}

static void	dfs(t_game *copy, int *count, char find_char)
{
	int	x;
	int	y;

	x = copy->player.col1;
	y = copy->player.row1;
	if (x < 0 || y < 0)
		return ;
	if (copy->map.data[y][x] == '1')
		return ;
	if (copy->map.data[y][x] != 'V')
	{
		if (copy->map.data[y][x] == find_char)
			(*count)++;
		copy->map.data[y][x] = 'V';
		call_dfs(copy, count, find_char);
	}
}

static void	duplicate(t_game *game, t_game *copy)
{
	int		i;
	int		j;

	copy->map.row = game->map.row;
	copy->map.col = game->map.col;
	copy->player.col1 = game->player.col1;
	copy->player.row1 = game->player.row1;
	malloc_map(copy);
	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			copy->map.data[i][j] = game->map.data[i][j];
			j++;
		}
		i++;
	}
}

void	check_explore_space(t_game *game)
{
	t_game	copy_c;
	t_game	copy_e;
	int		c_count;
	int		e_count;

	c_count = 0;
	e_count = 0;
	duplicate(game, &copy_c);
	duplicate(game, &copy_e);
	dfs(&copy_c, &c_count, 'C');
	dfs(&copy_e, &e_count, 'E');
	if (c_count != game->num.collec)
		error_exit(game, "Can't explore all collec\n");
	if (e_count != 1)
		error_exit(game, "Can't explore the exit\n");
}
