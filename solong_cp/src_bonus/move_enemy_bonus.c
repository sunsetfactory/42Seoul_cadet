#include "../include/so_long.h"

static void	move_horizon(t_game *game, int x)
{
	if (x == game->enemy.col2 * TILE_SIZE)
	{
		game->enemy.state = STANDING;
		game->enemy.col1 = game->enemy.col2;
		game->enemy.move_cnt = 0;
	}
	else
	{
		if (game->enemy.dir == RIGHT)
			game->enemy.pixel_x += 2;
		else if (game->enemy.dir == LEFT)
			game->enemy.pixel_x -= 2;
		game->enemy.move_cnt++;
	}
}

static void	move_vertical(t_game *game, int y)
{
	if (y == game->enemy.row2 * TILE_SIZE)
	{
		game->enemy.state = STANDING;
		game->enemy.row1 = game->enemy.row2;
		game->enemy.move_cnt = 0;
	}
	else
	{
		if (game->enemy.dir == UP)
			game->enemy.pixel_y -= 2;
		else if (game->enemy.dir == DOWN)
			game->enemy.pixel_y += 2;
		game->enemy.move_cnt++;
	}
}

void	move_enemy(t_game *game)
{
	int	wall;
	int	exit;
	int	collec;
	int	dir;

	if (game->enemy.state == STANDING)
		set_enemy_route(game);
	wall = wall_check_enemy(game);
	exit = exit_check_enemy(game);
	collec = collec_check_enemy(game);
	dir = game->enemy.dir;
	if (wall == 0 && exit == 0 && collec == 0)
	{
		if (game->enemy.dir == RIGHT || game->enemy.dir == LEFT)
			move_horizon(game, game->enemy.pixel_x);
		else if (game->enemy.dir == UP || game->enemy.dir == DOWN)
			move_vertical(game, game->enemy.pixel_y);
		check_catch_player(game);
	}
	else
		reset_enemy_route(game);
}
