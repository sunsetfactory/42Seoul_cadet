/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:52:30 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/10 14:52:57 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collec_check(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = game->player.col2;
	y = game->player.row2;
	i = -1;
	while (game->collec[++i])
	{
		if (game->collec[i]->col == x && game->collec[i]->row == y
			&& game->collec[i]->get == 0)
		{
			game->collec[i]->get = 1;
			game->num.collec--;
			if (game->num.collec == 0)
				game->exit.state = OPEN;
		}
	}
}

int	exit_check(t_game *game)
{
	int	row2;
	int	col2;

	row2 = game->player.row2;
	col2 = game->player.col2;
	if (game->map.data[row2][col2] == 'E' && game->exit.state == CLOSE)
		return (1);
	else if (game->map.data[row2][col2] == 'E' && game->exit.state == OPEN)
		game->state = END;
	return (0);
}

int	wall_check(t_game *game)
{
	int	row2;
	int	col2;

	row2 = game->player.row2;
	col2 = game->player.col2;
	if (game->map.data[row2][col2] == '1')
		return (1);
	return (0);
}
