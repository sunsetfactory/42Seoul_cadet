/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:29:42 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/10 17:03:12 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_wall_leak(t_game *game)
{
	int	i;
	int	row;
	int	col;

	row = game->map.row;
	col = game->map.col;
	i = 0;
	while (i < col)
	{
		if (game->map.data[0][i] != '1' || game->map.data[row - 1][i] != '1')
			error_exit(game, "error : wall reak\n");
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (game->map.data[i][0] != '1' || game->map.data[i][col - 1] != '1')
			error_exit(game, "error : wall reak\n");
		i++;
	}
}

static void	check_valid_compo(t_game *game)
{
	int		i;
	int		row;
	int		col;
	char	c;

	i = 0;
	row = -1;
	while (++row < game->map.row)
	{
		col = -1;
		while (++col < game->map.col)
		{
			c = game->map.data[row][col];
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				error_exit(game, "error : invalid compo\n");
		}
	}
}

static void	check_rec_and_get_row_col(t_game *game, char *map_name)
{
	char	*line;
	int		width;
	int		row;
	int		height;
	int		fd;

	fd = ft_open_file(game, map_name);
	row = -1;
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (row == -1)
			row = ft_strlen(line);
		else
		{
			width = ft_strlen(line);
			if (row != width)
				error_exit(game, "error : is not rectangle\n");
		}
		height++;
		free(line);
	}
	game->map.col = width;
	game->map.row = height;
	close(fd);
}

void	check_map(t_game *game, char *map_name)
{
	check_rec_and_get_row_col(game, map_name);
	make_map(game, map_name);
	check_valid_compo(game);
	check_wall_leak(game);
}
