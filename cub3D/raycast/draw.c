/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:55:26 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:28:56 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	pick_texture(t_param *param)
{
	int		texture_index;

	if (param->rc->side == 0)
	{
		if (param->rc->ray_x > 0)
			texture_index = 2;
		else
			texture_index = 3;
	}
	else
	{
		if (param->rc->ray_y > 0)
			texture_index = 0;
		else
			texture_index = 1;
	}
	return (texture_index);
}

void	set_texture(t_param *param, t_draw *draw)
{
	t_img	*texs;

	param->img->texture_index = pick_texture(param);
	texs = &param->texs[param->img->texture_index];
	texs->tex_x = (int)(draw->wall_x * (double)TEXTURE_WIDTH);
	if (param->rc->side == 0 && param->rc->ray_x > 0)
		texs->tex_x = TEXTURE_WIDTH - texs->tex_x - 1;
	if (param->rc->side == 1 && param->rc->ray_y < 0)
		texs->tex_x = TEXTURE_WIDTH - texs->tex_x - 1;
}

int	get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + y * img->len + x * (img->bpp / 8);
	return (*(int *)dst);
}

void	wall_draw(t_param *param, t_draw *draw, t_img *img, int x)
{
	int				y;
	int				d;
	unsigned int	color;
	t_img			*texs;

	y = draw->draw_start;
	texs = &param->texs[img->texture_index];
	while (y < draw->draw_end)
	{
		d = y * 256 - WIN_HEIGHT * 128 + draw->line_height * 128;
		texs->tex_y = ((d * TEXTURE_HEIGHT) / draw->line_height) / 256;
		if (texs->tex_y < 0)
			texs->tex_y = 0;
		if (texs->tex_y >= TEXTURE_HEIGHT)
			texs->tex_y = (TEXTURE_HEIGHT - 1);
		color = get_color(texs, texs->tex_x, texs->tex_y);
		if (color >= 0xFF000000)
			color = 0x0;
		*(int *)(img->addr + (y * img->len + x * (img->bpp / 8))) = color;
		y++;
	}
}

void	clear_screen(t_param *param)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
			*(int *)(param->img->addr + (y * param->img->len + x++ *\
				(param->img->bpp / 8))) = param->ceiling_color;
		y++;
	}
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			*(int *)(param->img->addr + (y * param->img->len + x++ *\
				(param->img->bpp / 8))) = param->floor_color;
		y++;
	}
}
