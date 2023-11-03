#include "../include/so_long.h"

static void	put_wall_img(t_game *game, int row, int col)
{
	int	x;
	int	y;

	x = col * TILE_SIZE;
	y = row * TILE_SIZE;
	if (row == 0 && col == 0)
		put_img(game, game->img.wall_nw, x, y);
	else if (row == 0 && col == game->map.col - 1)
		put_img(game, game->img.wall_ne, x, y);
	else if (row == game->map.row - 1 && col == 0)
		put_img(game, game->img.wall_sw, x, y);
	else if (row == game->map.row - 1 && col == game->map.col - 1)
		put_img(game, game->img.wall_se, x, y);
	else if (row == 0)
		put_img(game, game->img.wall_n, x, y);
	else if (row == game->map.row - 1)
		put_img(game, game->img.wall_s, x, y);
	else if (col == 0)
		put_img(game, game->img.wall_w, x, y);
	else if (col == game->map.col - 1)
		put_img(game, game->img.wall_e, x, y);
	else
		put_img(game, game->img.wall_box, x, y);
}

void	draw_wall(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			if (game->map.data[row][col] == '1')
				put_wall_img(game, row, col);
			col++;
		}
		row++;
	}
}
