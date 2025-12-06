/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:56:11 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:16:23 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_rc(t_param *param)
{
	param->rc->pos_x = -1;
	param->rc->pos_y = -1;
	param->rc->dir_x = 0.0;
	param->rc->dir_y = 0.0;
	param->rc->plane_x = 0.0;
	param->rc->plane_y = 0.0;
}

void	init_texs(t_param *param)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		param->texs[i].img = NULL;
		param->texs[i].w = 64;
		param->texs[i].h = 64;
		i++;
	}
}

void	init_param(t_param *param)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		param->f_color[i] = -1;
		param->c_color[i] = -1;
		i++;
	}
	init_texs(param);
	param->map_width = -1;
	param->map_height = -1;
	param->map_file_name = NULL;
	init_rc(param);
}

void	init_mlx(t_param *param)
{
	param->mlx->mlx = mlx_init();
	if (param->mlx->mlx == NULL)
		ft_exit("Allocate error");
	param->mlx->win = mlx_new_window(param->mlx->mlx, \
		WIN_WIDTH, WIN_HEIGHT, "cub3D");
}

void	init_img(t_mlx *mlx, t_img *img)
{
	img->w = WIN_WIDTH;
	img->h = WIN_HEIGHT;
	img->img = mlx_new_image(mlx->mlx, img->w, img->h);
	img->addr = mlx_get_data_addr \
		(img->img, &(img->bpp), &(img->len), &(img->endian));
}
