#include "../include/so_long.h"

void	check_rec_and_get_row_col(t_game *game, char *map_name)
{
	char	*line;
	int		width;
	int		row0;
	int		height;
	int		fd;

	fd = ft_open_file(game, map_name);
	row0 = -42;
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (row0 == -42)
			row0 = ft_strlen(line);
		else
		{
			width = ft_strlen(line);
			if (row0 != width)
				error_exit(game, "error : is not rectangle\n");
		}
		height++;
		free(line);
	}
	game->map.col = width;
	game->map.row = height;
	close(fd);
}

void	check_wall_leak(t_game *game)
{
	int	i;
	int	row;
	int	col;

	row = game->map.row;
	col = game->map.col;
	i = 0;
	while (i < col)
	{
		if (game->map.data[0][i] != '1' || game->map.data[row - 1][i] != '1')
			error_exit(game, "error : wall reak\n");
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (game->map.data[i][0] != '1' || game->map.data[i][col - 1] != '1')
			error_exit(game, "error : wall reak\n");
		i++;
	}
}
