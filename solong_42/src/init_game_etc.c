/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_etc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:56:13 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/08 15:13:12 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_game_cnt(t_game *game)
{
	game->player.move_cnt = 0;
	game->exit.move_cnt = 0;
	game->step = 0;
}

static void	init_game_state(t_game *game)
{
	game->state = PLAYING;
	game->player.state = STANDING;
	if (game->num.collec > 0)
		game->exit.state = CLOSE;
	else
		error_exit(game, "error : none collectible\n");
}

static void	init_game_img(t_game *game)
{
	game->img.tile = get_img(game, IMG_PATH "tile.xpm");
	game->img.collec = get_img(game, IMG_PATH "button.xpm");
	game->img.step_bg = get_img(game, IMG_PATH "step_bg.xpm");
	game->img.wall_box = get_img(game, IMG_PATH "wall_BOX.xpm");
	game->img.sprite_r = get_img(game, IMG_PATH "sprite_R.xpm");
	game->img.sprite_l = get_img(game, IMG_PATH "sprite_L.xpm");
	game->img.exit = get_img(game, IMG_PATH "exit.xpm");
	game->player.chosen_img = game->img.sprite_r;
}

static void	init_game_mlx(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE * game->map.col;
	height = TILE_SIZE * game->map.row;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void	init_game_etc(t_game *game)
{
	init_game_mlx(game);
	init_game_img(game);
	init_game_state(game);
	init_game_cnt(game);
}
