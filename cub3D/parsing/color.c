/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:48 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:55:27 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	check_element(char *line, int i)
{
	int	cnt;

	cnt = 0;
	while (line[i])
	{
		if (line[i] == ',')
			cnt++;
		if (!(line[i] >= '0' && line[i] <= '9') \
			&& !is_space(line[i]) && line[i] != ',')
			ft_exit("Invalid color element");
		i++;
	}
	if (cnt != 2)
		ft_exit("Invalid color");
}

void	color_check(t_param *param, int type)
{
	if (type == T_F)
	{
		if (param->f_color[0] != -1 || param->f_color[1] != -1 \
			|| param->f_color[2] != -1)
			ft_exit("Duplicate color");
	}
	else
	{
		if (param->c_color[0] != -1 || param->c_color[1] != -1 \
			|| param->c_color[2] != -1)
			ft_exit("Duplicate color");
	}
}

void	color_line_check(char *line)
{
	char	**color;
	int		row;

	row = 0;
	color = ft_split(line, ' ');
	while (color[row])
		row++;
	if (row > 1)
		ft_exit("Invalid color element");
	ft_free(color);
}

void	find_color(char *line, t_param *param, int type, int i)
{
	int		row;
	int		value;
	char	**color;

	row = 0;
	color_check(param, type);
	while (is_space(line[i]))
		i++;
	check_element(line, i);
	color = ft_split(line + i, ',');
	while (color[row])
	{
		color_line_check(color[row]);
		value = ft_atoi(color[row]);
		if (value < 0 || value > 255)
			ft_exit("Invalid color");
		if (type == T_C)
			param->c_color[row] = value;
		else
			param->f_color[row] = value;
		row++;
	}
	ft_free(color);
}
