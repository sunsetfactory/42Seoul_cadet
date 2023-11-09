/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_compone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:36:24 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/09 17:24:32 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_exit_opening(t_game *game, int x, int y)
{
	put_img(game, &game->img.exit[4], x, y);
	game->exit.move_cnt++;
	if (game->exit.move_cnt >= 31)
	{
		game->exit.move_cnt = 0;
		game->exit.state = OPEN;
	}
}

void	draw_player(t_game *game)
{
	int		x;
	int		y;
	int		m_cnt;
	void	**img;

	x = game->player.pixel_x;
	y = game->player.pixel_y;
	m_cnt = game->player.move_cnt;
	img = game->player.chosen_img;
	put_img(game, img, x, y);
}

static void	draw_exit(t_game *game)
{
	int	x;
	int	y;
	int	m_cnt;

	m_cnt = game->exit.move_cnt;
	x = game->exit.col * TILE_SIZE;
	y = game->exit.row * TILE_SIZE;
	put_img(game, game->img.exit, x, y);
	if (game->exit.state == OPEN)
		put_img(game, game->img.exit, x, y);
	else if (game->exit.state == CLOSE)
		put_img(game, game->img.exit, x, y);
	draw_exit_opening(game, x, y);
}

static void	draw_collec(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	if (game->collec)
	{
		while (game->collec[++i])
		{
			if (game->collec[i]->get == 0)
			{
				x = game->collec[i]->col * TILE_SIZE;
				y = game->collec[i]->row * TILE_SIZE;
				put_img(game, game->img.collec, x, y);
			}
		}
	}
}

void	draw_compo(t_game *game)
{
	draw_collec(game);
	draw_exit(game);
}

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
