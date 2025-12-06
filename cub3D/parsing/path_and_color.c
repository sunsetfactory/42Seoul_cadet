/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_and_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:16:39 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/25 19:49:05 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_path_and_color(char *line, t_param *param, int type)
{
	if (type == FALSE)
		ft_exit("Lack of map elements");
	if (type == T_NO || type == T_SO || type == T_WE || type == T_EA)
		find_path(line, param, type);
	else if (type == T_C || type == T_F)
		find_color(line, param, type, 1);
}

void	find_path_and_color(char *line, t_param *param)
{
	char	**temp;
	int		row;
	int		i;

	temp = ft_split(line, '\n');
	row = 0;
	while (temp[row])
	{
		i = 0;
		while (is_space(temp[row][i]))
			i++;
		if (check_type(temp[row]) == FALSE || \
			(check_type(temp[row]) == TRUE && i > 0))
			break ;
		put_path_and_color(temp[row] + i, param, check_type(temp[row]));
		row++;
	}
	param->floor_color = rgb_to_hex(param->f_color[0], \
		param->f_color[1], param->f_color[2]);
	param->ceiling_color = rgb_to_hex(param->c_color[0], \
		param->c_color[1], param->c_color[2]);
	row = 0;
	while (temp[row])
		free(temp[row++]);
	free(temp);
}
