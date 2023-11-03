#include "../include/so_long.h"

void	draw_all(t_game *game)
{
	draw_wall(game);
	draw_tile(game);
	draw_compo(game);
	draw_player(game);
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

int	main(int argc, char **argv)
{
	t_game	game;

	game.version = MANDATORY;
	init_game_malloc_ptr(&game);
	if (argc != 2)
		error_exit(&game, "Usage : ./so_long map/<map_name.ber>\n");
	check_filename(&game, argv[1]);
	check_map(&game, argv[1]);
	check_compo(&game);
	init_game_mlx(&game);
	init_game_img(&game);
	init_game_state(&game);
	init_game_etc(&game);
	draw_all(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_loop_hook(game.mlx, &loop_draw, &game);
	printf(SKY "--------------------\n     "
		"start game\n--------------------\n" RESET);
	mlx_loop(game.mlx);
	return (0);
}
