/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:40:55 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/01 18:07:22 by seokjyan         ###   ########.fr       */
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

void	error_exit(t_game *game, char *msg)
{
	free_map_data(game);
	free_collec_list(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_putstr_fd(RED "-------------------------\n ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("-------------------------\n" RESET, 2);
	exit(1);
}

void	init_game_malloc_ptr(t_game *game)
{
	game->collec = NULL;
	game->map.data = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_malloc_ptr(&game);
	if (argc != 2)
		error_exit(&game, "Usage : ./so_long map/<map_name.ber>\n");
	return (0);
}
