/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:07:52 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:55:28 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_img(t_param *param, int type, char *path)
{
	if (type == T_EA)
		param->texs[0].img = mlx_xpm_file_to_image \
			(param->mlx->mlx, path, &param->texs[0].w, &param->texs[0].h);
	else if (type == T_WE)
		param->texs[1].img = mlx_xpm_file_to_image \
			(param->mlx->mlx, path, &param->texs[1].w, &param->texs[1].h);
	else if (type == T_SO)
		param->texs[2].img = mlx_xpm_file_to_image \
			(param->mlx->mlx, path, &param->texs[2].w, &param->texs[2].h);
	else if (type == T_NO)
		param->texs[3].img = mlx_xpm_file_to_image \
			(param->mlx->mlx, path, &param->texs[3].w, &param->texs[3].h);
	else
		ft_exit("Wrong path");
}

void	put_addr(t_param *param)
{
	param->texs[0].addr = mlx_get_data_addr(param->texs[0].img, \
		&param->texs[0].bpp, &param->texs[0].len, &param->texs[0].endian);
	param->texs[1].addr = mlx_get_data_addr(param->texs[1].img, \
		&param->texs[1].bpp, &param->texs[1].len, &param->texs[1].endian);
	param->texs[2].addr = mlx_get_data_addr(param->texs[2].img, \
		&param->texs[2].bpp, &param->texs[2].len, &param->texs[2].endian);
	param->texs[3].addr = mlx_get_data_addr(param->texs[3].img, \
		&param->texs[3].bpp, &param->texs[3].len, &param->texs[3].endian);
}
