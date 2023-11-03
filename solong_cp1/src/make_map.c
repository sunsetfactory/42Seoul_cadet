#include "../include/so_long.h"

void	malloc_map(t_game *game)
{
	int	i;

	game->map.data = (char **)malloc(sizeof(char *) * (game->map.row + 1));
	if (game->map.data == NULL)
		error_exit(game, "malloc error\n");
	i = 0;
	while (i < game->map.row)
	{
		game->map.data[i] = (char *)calloc((game->map.col + 1), sizeof(char));
		if (game->map.data[i] == NULL)
			error_exit(game, "malloc error\n");
		i++;
	}
	game->map.data[i] = NULL;
}

void	make_map(t_game *game, char *map_name)
{
	char	*line;
	int		fd;
	int		i;

	malloc_map(game);
	fd = ft_open_file(game, map_name);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i < game->map.row)
			ft_strlcpy(game->map.data[i], line, (game->map.col + 1));
		free(line);
		i++;
	}
	close(fd);
}
