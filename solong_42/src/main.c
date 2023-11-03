/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:40:55 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/03 17:35:05 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_all(t_game *game)
{
	draw_wall(game); // 수정 필요
	draw_tile(game);
	draw_compo(game);
	draw_player(game);
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

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_malloc_ptr(&game);
	if (argc != 2)
		error_exit(&game, "Usage : ./so_long map/<map_name.ber>\n");
	check_filename(&game, argv[1]);
	check_map(&game, argv[1]);
	check_compo(&game);
	init_game_etc(&game);
	draw_all(&game);
	return (0);
}
