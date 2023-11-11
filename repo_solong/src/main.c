/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:40:55 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/10 19:25:25 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_all(t_game *game)
{
	draw_wall(game);
	draw_tile(game);
	draw_compo(game);
	draw_player(game);
}

int	loop_draw(t_game *game)
{
	if (game->player.state == STANDING && game->state == END)
		normal_exit(game);
	if (game->player.col1 < game->player.col2)
		move_player(game, RIGHT);
	else if (game->player.col1 > game->player.col2)
		move_player(game, LEFT);
	else if (game->player.row1 < game->player.row2)
		move_player(game, DOWN);
	else if (game->player.row1 > game->player.row2)
		move_player(game, UP);
	draw_all(game);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		normal_exit(game);
	else if (game->player.state == STANDING)
	{
		game->player.state = WALKING;
		if (keycode == KEY_RIGHT || keycode == KEY_D)
			game->player.col2++;
		else if (keycode == KEY_LEFT || keycode == KEY_A)
			game->player.col2--;
		else if (keycode == KEY_UP || keycode == KEY_W)
			game->player.row2--;
		else if (keycode == KEY_DOWN || keycode == KEY_S)
			game->player.row2++;
	}
	return (0);
}

int	red_exit(t_game *game)
{
	normal_exit(game);
	return (0);
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
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, KEY_RED, 0, &red_exit, &game);
	mlx_loop_hook(game.mlx, &loop_draw, &game);
	ft_putstr_fd(SKY "--------------------\n     ", STDOUT);
	ft_putstr_fd("start game\n--------------------\n" RESET, STDOUT);
	mlx_loop(game.mlx);
	return (0);
}
