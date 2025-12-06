/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:59 by seokjyan          #+#    #+#             */
/*   Updated: 2024/02/29 15:05:08 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_param *param, t_draw *draw, t_img *img)
{
	int	x;

	x = 0;
	clear_screen(param);
	while (x < WIN_WIDTH)
	{
		set_ray(param, x);
		set_step_dist(param);
		dda(param);
		check_perp(param);
		set_draw(param, draw);
		set_texture(param, draw);
		wall_draw(param, draw, img, x);
		x++;
	}
	mlx_put_image_to_window(param->mlx->mlx, \
		param->mlx->win, param->img->img, 0, 0);
}

int	main_loop(t_param *param)
{
	t_draw	draw;

	raycasting(param, &draw, param->img);
	return (0);
}
