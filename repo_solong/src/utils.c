/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:32:52 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/08 15:11:32 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*get_img(t_game *game, char *file)
{
	int		w;
	int		h;
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
	if (!img_ptr)
		error_exit(game, "error : get_img()\n");
	if (w != 64 || h != 64)
		error_exit(game, "error : xpm img size is not 64x64\n");
	return (img_ptr);
}

int	ft_open_file(t_game *game, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		error_exit(game, "error open_file\n");
	return (fd);
}
