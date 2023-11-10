/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:30:18 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/10 14:35:13 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_tile(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < game->map.row)
	{
		c = 0;
		while (c < game->map.col)
		{
			if (game->map.data[r][c] != '1')
				put_img(game, game->img.tile, c * TILE_SIZE, r * TILE_SIZE);
			c++;
		}
		r++;
	}
}

void	draw_wall(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			if (game->map.data[row][col] == '1')
				put_img(game, game->img.wall_box, \
				col * TILE_SIZE, row * TILE_SIZE);
			col++;
		}
		row++;
	}
}
