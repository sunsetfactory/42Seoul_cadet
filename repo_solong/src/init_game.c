/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:36:37 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/03 16:37:38 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game_num(t_game *game)
{
	game->num.collec = 0;
	game->num.exit = 0;
	game->num.player = 0;
}

void	init_game_malloc_ptr(t_game *game)
{
	game->collec = NULL;
	game->map.data = NULL;
	game->mlx = NULL;
	game->win = NULL;
}
