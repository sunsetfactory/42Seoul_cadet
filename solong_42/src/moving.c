/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:00:53 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/08 14:44:59 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	mark_down(t_game *game)
{
	if (game->player.move_cnt >= 16)
	{
		game->player.state = STANDING;
		game->player.col2 = game->player.col1;
		game->player.row2 = game->player.row1;
		game->player.move_cnt = 0;
	}
	else
		game->player.move_cnt++;
}

static void	move_vertical(t_game *game, int dir, int y)
{
	if (y == game->player.row2 * TILE_SIZE)
	{
		printf("step : %d\n", ++game->step);
		game->player.state = STANDING;
		game->player.row1 = game->player.row2;
		game->player.move_cnt = 0;
	}
	else
	{
		if (dir == UP)
			game->player.pixel_y -= 4;
		else if (dir == DOWN)
			game->player.pixel_y += 4;
		game->player.move_cnt++;
	}
}

static void	move_horizon(t_game *game, int dir, int x)
{
	if (x == game->player.col2 * TILE_SIZE)
	{
		printf("step : %d\n", ++game->step);
		game->player.state = STANDING;
		game->player.col1 = game->player.col2;
		game->player.move_cnt = 0;
	}
	else
	{
		if (dir == RIGHT)
			game->player.pixel_x += 4;
		else if (dir == LEFT)
			game->player.pixel_x -= 4;
		game->player.move_cnt++;
	}
}

void	collec_check(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = game->player.col2;
	y = game->player.row2;
	i = -1;
	while (game->collec[++i])
	{
		if (game->collec[i]->col == x && game->collec[i]->row == y
			&& game->collec[i]->get == 0)
		{
			game->collec[i]->get = 1;
			game->num.collec--;
			if (game->num.collec == 0)
				game->exit.state = OPENING;
		}
	}
}

int	exit_check(t_game *game)
{
	int	row2;
	int	col2;

	row2 = game->player.row2;
	col2 = game->player.col2;
	if (game->map.data[row2][col2] == 'E' && game->exit.state == CLOSE)
		return (1);
	else if (game->map.data[row2][col2] == 'E' && game->exit.state == OPEN)
		game->state = END;
	return (0);
}

int	wall_check(t_game *game)
{
	int	row2;
	int	col2;

	row2 = game->player.row2;
	col2 = game->player.col2;
	if (game->map.data[row2][col2] == '1')
		return (1);
	return (0);
}

void	choice_player_img(t_game *game, int dir)
{
	if (dir == RIGHT)
		game->player.chosen_img = game->img.sprite_r;
	else if (dir == LEFT)
		game->player.chosen_img = game->img.sprite_l;
}

void	move_player(t_game *game, int dir)
{
	int	wall;
	int	exit;

	choice_player_img(game, dir);
	wall = wall_check(game);
	exit = exit_check(game);
	collec_check(game);
	if (wall == 0 && exit == 0)
	{
		if (dir == RIGHT || dir == LEFT)
			move_horizon(game, dir, game->player.pixel_x);
		else if (dir == UP || dir == DOWN)
			move_vertical(game, dir, game->player.pixel_y);
	}
	else
		mark_down(game);
}
