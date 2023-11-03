#include "../include/so_long.h"

void	draw_tile(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < game->map.row)
	{
		c = 0;
		while (c < game->map.col)
		{
			if (game->map.data[r][c] != '1')
				put_img(game, game->img.tile, c * TILE_SIZE, r * TILE_SIZE);
			c++;
		}
		r++;
	}
}
