/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:11:33 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/01 16:04:42 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init = Link screens and create identifiers (return : identifiers or NULL)
void	*init_mlx(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		exit(1);
	return (mlx);
}

// new_window = create window and identifiers (return : identifiers or NULL)
void	*new_window_mlx(t_info info, int x, int y, char *c)
{
	void	*win;

	win = mlx_new_window(info.mlx, x, y, c);
	if (!win)
		exit(1);
	return (win);
}

// xpm_file_to_image = make image data (return : identifiers or NULL)
void	*make_image(t_info info, char *c, int *x, int *y)
{
	void	*res;

	res = mlx_xpm_file_to_image(info.mlx, c, x, y);
	if (!res)
		exit(1);
	return (res);
}
// mlx_put_image_to_window = 

int	init(t_info *info)
{
	info->map.ball = mlx_xpm_file_to_image(info->mlx, BALL_XPM, \
											&info->img_x, &info->img_y);
	info->map.tile = mlx_xpm_file_to_image(info->mlx, TILE_XPM, \
											&info->img_x, &info->img_y);
	info->map.wall = mlx_xpm_file_to_image(info->mlx, GOJIJI_XPM, \
											&info->img_x, &info->img_y);
	info->map.jiu = mlx_xpm_file_to_image(info->mlx, JIU_XPM, \
											&info->img_x, &info->img_y);
	if (!info->map.ball || !info->map.tile || !info->map.wall || !info->map.jiu)
		return (-1);
	return (1);
}

int	make_map(t_info *info)
{
	if (!mlx_put_image_to_window(info->mlx, info->win, info->map.ball, 0, 0))
		return (-1);
	if (!mlx_put_image_to_window(info->mlx, info->win, info->map.tile, 64, 0))
		return (-1);
	if (!mlx_put_image_to_window(info->mlx, info->win, info->map.wall, 128, 0))
		return (-1);
	if (!mlx_put_image_to_window(info->mlx, info->win, info->map.jiu, 0, 64))
		return (-1);
	return (1);
}
