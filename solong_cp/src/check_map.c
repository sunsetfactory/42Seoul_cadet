#include "../include/so_long.h"

static void	check_valid_compo_val(t_game *game, char c)
{
	if (game->version == MANDATORY)
	{
		if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
			error_exit(game, "error : invalid compo\n");
	}
	else if (game->version == BONUS)
	{
		if (c != '0' && c != '1' && c != 'P'
			&& c != 'C' && c != 'E' && c != 'N')
			error_exit(game, "error : invalid compo\n");
	}
}

static void	check_valid_compo(t_game *game)
{
	int		i;
	int		row;
	int		col;
	char	c;

	i = 0;
	row = -1;
	while (++row < game->map.row)
	{
		col = -1;
		while (++col < game->map.col)
		{
			c = game->map.data[row][col];
			check_valid_compo_val(game, c);
		}
	}
}

void	check_map(t_game *game, char *map_name)
{
	check_rec_and_get_row_col(game, map_name);
	make_map(game, map_name);
	check_valid_compo(game);
	check_wall_leak(game);
}
