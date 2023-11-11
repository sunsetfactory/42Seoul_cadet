/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:28:05 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/10 14:56:30 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map_data(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.data)
	{
		while (i < game->map.row)
		{
			free(game->map.data[i]);
			i++;
		}
		free(game->map.data);
	}
}

void	free_collec_list(t_game *game)
{
	int	i;

	i = 0;
	if (game->collec)
	{
		while (game->collec[i])
		{
			free(game->collec[i]);
			i++;
		}
		free(game->collec);
	}
}
