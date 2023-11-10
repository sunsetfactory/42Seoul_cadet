/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:36:24 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/10 14:49:07 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_player(t_game *game)
{
	int		x;
	int		y;
	void	**img;

	x = game->player.pixel_x;
	y = game->player.pixel_y;
	img = game->player.chosen_img;
	put_img(game, img, x, y);
}

static void	draw_exit(t_game *game)
{
	int		x;
	int		y;
	void	**img;

	x = game->exit.col * TILE_SIZE;
	y = game->exit.row * TILE_SIZE;
	img = game->img.exit;
	put_img(game, game->img.exit, x, y);
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
