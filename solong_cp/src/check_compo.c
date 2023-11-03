#include "../include/so_long.h"

static void	count_compo(t_game *game)
{
	int	r;
	int	c;

	r = -1;
	while (++r < game->map.row)
	{
		c = -1;
		while (++c < game->map.col)
		{
			if (game->map.data[r][c] == 'P')
				game->num.player++;
			else if (game->map.data[r][c] == 'E')
				game->num.exit++;
			else if (game->map.data[r][c] == 'C')
				game->num.collec++;
			if (game->num.player > 1 || game->num.exit > 1)
				error_exit(game, "error : player or exit number is over\n");
		}
	}
	if (game->num.player == 0 || game->num.exit == 0
		|| game->num.collec == 0)
		error_exit(game, "error : none player or exit or collectible\n");
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

void static	set_compo_val(t_game *game)
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
			if (game->map.data[row][col] == 'C')
				i++;
		}
	}
}

void	check_compo(t_game *game)
{
	init_game_num(game);
	count_compo(game);
	make_collec_list(game);
	set_compo_val(game);
}
