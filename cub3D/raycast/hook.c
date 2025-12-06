/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:35:49 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:06:07 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move(double x, double y, t_param *param)
{
	double	move_speed;
	t_rc	*rc;

	move_speed = 0.537;
	rc = param->rc;
	x *= move_speed;
	y *= move_speed;
	if (param->world_map[(int)(rc->pos_x + x)][(int)(rc->pos_y)] == '0')
		param->rc->pos_x += x;
	if (param->world_map[(int)(rc->pos_x)][(int)(rc->pos_y + y)] == '0')
		param->rc->pos_y += y;
}

void	ray_hook(double rot_angle, t_param *param)
{
	double	old_dir;
	double	old_plane;
	t_rc	*rc;

	old_dir = param->rc->dir_x;
	old_plane = param->rc->plane_x;
	rc = param->rc;
	rc->dir_x = old_dir * cos(rot_angle) - rc->dir_y * sin(rot_angle);
	rc->dir_y = old_dir * sin(rot_angle) + rc->dir_y * cos(rot_angle);
	rc->plane_x = old_plane * cos(rot_angle) - rc->plane_y * sin(rot_angle);
	rc->plane_y = old_plane * sin(rot_angle) + rc->plane_y * cos(rot_angle);
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == 13)
		move(param->rc->dir_x, param->rc->dir_y, param);
	if (keycode == 1)
		move(-(param->rc->dir_x), -(param->rc->dir_y), param);
	if (keycode == 0)
		move(-param->rc->dir_y, param->rc->dir_x, param);
	if (keycode == 2)
		move(param->rc->dir_y, -param->rc->dir_x, param);
	if (keycode == 123)
		ray_hook(0.05, param);
	if (keycode == 124)
		ray_hook(-0.05, param);
	if (keycode == 53)
		exit(0);
	return (0);
}
