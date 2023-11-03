#include "../include/so_long.h"

static void	input_val_enemy(t_game *game, int row, int col)
{
	if (game->map.data[row][col] == 'N')
	{
		game->enemy.pixel_x = col * TILE_SIZE;
		game->enemy.pixel_y = row * TILE_SIZE;
		game->enemy.col1 = col;
		game->enemy.col2 = col;
		game->enemy.row1 = row;
		game->enemy.row2 = row;
	}
}

static void	input_val(t_game *game, int row, int col, int i)
{
	if (game->map.data[row][col] == 'P')
	{
		game->player.pixel_x = col * TILE_SIZE;
		game->player.pixel_y = row * TILE_SIZE;
		game->player.col1 = col;
		game->player.col2 = col;
		game->player.row1 = row;
		game->player.row2 = row;
	}
	else if (game->map.data[row][col] == 'E')
	{
		game->exit.col = col;
		game->exit.row = row;
	}
	else if (game->map.data[row][col] == 'C')
	{
		game->collec[i]->get = 0;
		game->collec[i]->col = col;
		game->collec[i]->row = row;
	}
}

void	set_compo_val_b(t_game *game)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = -1;
	while (++row < game->map.row)
	{
		col = -1;
		while (++col < game->map.col)
		{
			input_val(game, row, col, i);
			input_val_enemy(game, row, col);
			if (game->map.data[row][col] == 'C')
				i++;
		}
	}
}
