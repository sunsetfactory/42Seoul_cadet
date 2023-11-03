#include "../include/so_long.h"

void	get_dir(t_game *game)
{
	int	p_col;
	int	p_row;
	int	e_col;
	int	e_row;

	p_col = game->player.col1;
	p_row = game->player.row1;
	e_col = game->enemy.col1;
	e_row = game->enemy.row1;
	if (ft_abs(p_col - e_col) > ft_abs(p_row - e_row))
	{
		if (p_col > e_col)
			game->enemy.dir = RIGHT;
		else
			game->enemy.dir = LEFT;
	}
	else
	{
		if (p_row > e_row)
			game->enemy.dir = DOWN;
		else
			game->enemy.dir = UP;
	}
}

void	set_enemy_route(t_game *game)
{
	get_dir(game);
	choice_enemy_img(game);
	set_row2_col2(game);
	game->enemy.state = WALKING;
}

void	change_dir(t_game *game)
{
	if (game->enemy.dir == RIGHT)
		game->enemy.dir = DOWN;
	else if (game->enemy.dir == DOWN)
		game->enemy.dir = LEFT;
	else if (game->enemy.dir == LEFT)
		game->enemy.dir = UP;
	else if (game->enemy.dir == UP)
		game->enemy.dir = RIGHT;
}

void	reset_enemy_route(t_game *game)
{
	game->enemy.row2 = game->enemy.row1;
	game->enemy.col2 = game->enemy.col1;
	change_dir(game);
	choice_enemy_img(game);
	set_row2_col2(game);
}

void	check_catch_player(t_game *game)
{
	int	len_w;
	int	len_h;

	len_w = ft_abs(game->enemy.pixel_x - game->player.pixel_x);
	len_h = ft_abs(game->enemy.pixel_y - game->player.pixel_y);
	if (len_w < 48 && len_h < 48)
		normal_exit(game);
}
