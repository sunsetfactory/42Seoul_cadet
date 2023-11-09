/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:57:08 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/09 16:25:40 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	if (!mlx_put_image_to_window(game->mlx, game->win, img, x, y))
		error_exit(game, "Failed to load graphics information");
}
