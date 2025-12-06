/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:24:48 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/25 19:48:57 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_vaild(t_param *param, int new_h, int new_w)
{
	if (new_h < 0 || new_w < 0 \
		|| new_h >= param->map_height + 2 || new_w >= param->map_width + 1)
		return ;
	if (!is_space(param->world_map[new_h][new_w]) \
		&& param->world_map[new_h][new_w] != '1')
		ft_exit("Invalid map");
}

int	check_char(t_param *param, int h, int w)
{
	if (ft_strchr(" 01NEWS\n", param->world_map[h][w]) == NULL)
		return (FALSE);
	return (TRUE);
}

void	check_side(t_param *param, int h, int w)
{
	int	new_h;
	int	new_w;
	int	dh[4];
	int	dw[4];
	int	i;

	dh[0] = -1;
	dh[1] = 1;
	dh[2] = 0;
	dh[3] = 0;
	dw[0] = 0;
	dw[1] = 0;
	dw[2] = -1;
	dw[3] = 1;
	i = 0;
	while (i < 4)
	{
		new_h = h + dh[i];
		new_w = w + dw[i];
		is_vaild(param, new_h, new_w);
		i++;
	}
}

void	check_player_pos(t_param *param, int h, int w)
{
	if (param->rc->pos_x != -1 || param->rc->pos_y != -1)
		ft_exit("Too many player");
	param->rc->pos_x = h + 0.5;
	param->rc->pos_y = w + 0.5;
	if (param->world_map[h][w] == 'W')
	{
		param->rc->dir_y = -1.0;
		param->rc->plane_x = -0.66;
	}
	else if (param->world_map[h][w] == 'E')
	{
		param->rc->dir_y = 1.0;
		param->rc->plane_x = 0.66;
	}
	else if (param->world_map[h][w] == 'N')
	{
		param->rc->dir_x = -1.0;
		param->rc->plane_y = 0.66;
	}
	else if (param->world_map[h][w] == 'S')
	{
		param->rc->dir_x = 1.0;
		param->rc->plane_y = -0.66;
	}
	param->world_map[h][w] = '0';
}

void	check_space(t_param *param)
{
	int	h;
	int	w;

	h = 0;
	while (param->world_map[h])
	{
		w = 0;
		while (w < param->map_width + 1)
		{
			if (!check_char(param, h, w))
				ft_exit("Wrong character");
			if (is_space(param->world_map[h][w]))
				check_side(param, h, w);
			if (ft_strchr("NSEW", param->world_map[h][w]))
				check_player_pos(param, h, w);
			w++;
		}
		h++;
	}
}
