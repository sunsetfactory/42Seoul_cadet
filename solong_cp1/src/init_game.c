#include "../include/so_long.h"

void	init_game_mlx(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE * game->map.col;
	height = TILE_SIZE * game->map.row;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void	init_game_malloc_ptr(t_game *game)
{
	game->collec = NULL;
	game->map.data = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

void	init_game_state(t_game *game)
{
	game->state = PLAYING;
	game->player.state = STANDING;
	game->enemy.state = STANDING;
	if (game->num.collec > 0)
		game->exit.state = CLOSE;
	else
		error_exit(game, "error : none collectible\n");
}

void	init_game_etc(t_game *game)
{
	game->player.move_cnt = 0;
	game->exit.move_cnt = 0;
	game->enemy.move_cnt = 0;
	game->enemy.dir = LEFT;
	game->step = 0;
}

void	init_game_num(t_game *game)
{
	game->num.collec = 0;
	game->num.exit = 0;
	game->num.enemy = 0;
	game->num.player = 0;
}
