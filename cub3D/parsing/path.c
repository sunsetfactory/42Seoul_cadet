/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:36:57 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:55:16 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	path_check(t_param *param, int type)
{
	int	index;

	index = 0;
	if (type == T_EA)
		index = 0;
	else if (type == T_WE)
		index = 1;
	else if (type == T_SO)
		index = 2;
	else if (type == T_NO)
		index = 3;
	else
		ft_exit("Wrong path");
	if (param->texs[index].img != NULL)
		ft_exit("Duplicate path");
}

void	find_path(char *line, t_param *param, int type)
{
	char	*path;
	int		i;

	i = 2;
	if (type == 0)
		ft_exit("Wrong path");
	while (is_space(line[i]))
		i++;
	path = mk_strdup(i, ft_strlen(line), line);
	path_check(param, type);
	put_img(param, type, path);
	param->map_height = 0;
	free(path);
}
