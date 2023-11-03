#include "../include/so_long.h"

static void	move_horizon(t_game *game, int dir, int x)
{
	if (x == game->player.col2 * TILE_SIZE)
	{
		printf("step : %d\n", ++game->step);
		game->player.state = STANDING;
		game->player.col1 = game->player.col2;
		game->player.move_cnt = 0;
	}
	else
	{
		if (dir == RIGHT)
			game->player.pixel_x += 4;
		else if (dir == LEFT)
			game->player.pixel_x -= 4;
		game->player.move_cnt++;
	}
}

static void	move_vertical(t_game *game, int dir, int y)
{
	if (y == game->player.row2 * TILE_SIZE)
	{
		printf("step : %d\n", ++game->step);
		game->player.state = STANDING;
		game->player.row1 = game->player.row2;
		game->player.move_cnt = 0;
	}
	else
	{
		if (dir == UP)
			game->player.pixel_y -= 4;
		else if (dir == DOWN)
			game->player.pixel_y += 4;
		game->player.move_cnt++;
	}
}

static void	mark_down(t_game *game)
{
	if (game->player.move_cnt >= 16)
	{
		game->player.state = STANDING;
		game->player.col2 = game->player.col1;
		game->player.row2 = game->player.row1;
		game->player.move_cnt = 0;
	}
	else
		game->player.move_cnt++;
}

void	move_player(t_game *game, int dir)
{
	int	wall;
	int	exit;

	choice_player_img(game, dir);
	wall = wall_check(game);
	exit = exit_check(game);
	collec_check(game);
	if (wall == 0 && exit == 0)
	{
		if (dir == RIGHT || dir == LEFT)
			move_horizon(game, dir, game->player.pixel_x);
		else if (dir == UP || dir == DOWN)
			move_vertical(game, dir, game->player.pixel_y);
	}
	else
		mark_down(game);
}
