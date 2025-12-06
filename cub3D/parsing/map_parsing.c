/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:21:19 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:37:13 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_vaild_arg(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (ft_strncmp(file_name + len - 4, ".cub", 4) == 0 && file_name[0] != '.')
		return (TRUE);
	else
		return (FALSE);
}

int	check_type(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (!ft_strncmp(line + i, "NO ", 3))
		return (T_NO);
	else if (!ft_strncmp(line + i, "SO ", 3))
		return (T_SO);
	else if (!ft_strncmp(line + i, "WE ", 3))
		return (T_WE);
	else if (!ft_strncmp(line + i, "EA ", 3))
		return (T_EA);
	else if (!ft_strncmp(line + i, "F ", 2))
		return (T_F);
	else if (!ft_strncmp(line + i, "C ", 2))
		return (T_C);
	else if (line[i] == '\n')
		return (TRUE);
	else
		return (FALSE);
}

void	error_check(t_param *param)
{
	if (param->texs[0].img == NULL || param->texs[1].img == NULL \
		|| param->texs[2].img == NULL || param->texs[3].img == NULL)
		ft_exit("Failed to import image");
	if (param->map_width <= 2 || param->map_height <= 2)
		ft_exit("A map that's too small");
	if (param->rc->pos_x < 0 || param->rc->pos_y < 0)
		ft_exit("No player");
	if ((int)param->floor_color == -1 || (int)param->ceiling_color == -1)
		ft_exit("Invalid color");
}

void	parse(t_param *param)
{
	if (!is_vaild_arg(param->map_file_name))
		ft_exit("Invalid argument");
	file_parsing(param);
	check_space(param);
	error_check(param);
	put_addr(param);
}
