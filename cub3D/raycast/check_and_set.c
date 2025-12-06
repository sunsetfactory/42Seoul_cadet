/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:52:44 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 14:55:17 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_ray(t_param *param, int x)
{
	param->rc->cam_x = 2 * x / (double)WIN_WIDTH - 1;
	param->rc->ray_x = param->rc->dir_x + param->rc->plane_x * param->rc->cam_x;
	param->rc->ray_y = param->rc->dir_y + param->rc->plane_y * param->rc->cam_x;
	param->rc->map_x = param->rc->pos_x;
	param->rc->map_y = param->rc->pos_y;
	param->rc->deltadist_x = fabs(1 / param->rc->ray_x);
	param->rc->deltadist_y = fabs(1 / param->rc->ray_y);
}

void	set_step_dist(t_param *param)
{
	if (param->rc->ray_x < 0)
	{
		param->rc->step_x = -1;
		param->rc->sidedist_x = \
		(param->rc->pos_x - param->rc->map_x) * param->rc->deltadist_x;
	}
	else
	{
		param->rc->step_x = 1;
		param->rc->sidedist_x = \
		(param->rc->map_x + 1 - param->rc->pos_x) * param->rc->deltadist_x;
	}
	if (param->rc->ray_y < 0)
	{
		param->rc->step_y = -1;
		param->rc->sidedist_y = \
		(param->rc->pos_y - param->rc->map_y) * param->rc->deltadist_y;
	}
	else
	{
		param->rc->step_y = 1;
		param->rc->sidedist_y = \
		(param->rc->map_y + 1 - param->rc->pos_y) * param->rc->deltadist_y;
	}
}

void	dda(t_param *param)
{
	while (1)
	{
		if (param->rc->sidedist_x < param->rc->sidedist_y)
		{
			param->rc->sidedist_x += param->rc->deltadist_x;
			param->rc->map_x += param->rc->step_x;
			param->rc->side = 0;
		}
		else
		{
			param->rc->sidedist_y += param->rc->deltadist_y;
			param->rc->map_y += param->rc->step_y;
			param->rc->side = 1;
		}
		if (param->world_map[param->rc->map_x][param->rc->map_y] == '1')
			break ;
	}
}

void	check_perp(t_param *param)
{
	if (param->rc->side == 0)
		param->rc->perpdist = param->rc->sidedist_x - param->rc->deltadist_x;
	else
		param->rc->perpdist = param->rc->sidedist_y - param->rc->deltadist_y;
}

void	set_draw(t_param *param, t_draw *draw)
{
	t_rc	*rc;

	rc = param->rc;
	draw->line_height = (int)(WIN_HEIGHT / rc->perpdist);
	draw->draw_start = -(draw->line_height) / 2 + WIN_HEIGHT / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + WIN_HEIGHT / 2;
	if (draw->draw_end >= WIN_HEIGHT)
		draw->draw_end = WIN_HEIGHT - 1;
	if (rc->side == 0)
		draw->wall_x = rc->pos_y + rc->perpdist * rc->ray_y;
	else
		draw->wall_x = rc->pos_x + rc->perpdist * rc->ray_x;
	draw->wall_x -= floor(draw->wall_x);
}
