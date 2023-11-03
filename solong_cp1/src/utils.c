#include "../include/so_long.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	free_map_data(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.data)
	{
		while (i < game->map.row)
		{
			free(game->map.data[i]);
			i++;
		}
		free(game->map.data);
	}
}

void	free_collec_list(t_game *game)
{
	int	i;

	i = 0;
	if (game->collec)
	{
		while (game->collec[i])
		{
			free(game->collec[i]);
			i++;
		}
		free(game->collec);
	}
}

int	ft_open_file(t_game *game, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		error_exit(game, "error open_file\n");
	return (fd);
}

void	*get_img(t_game *game, char *file)
{
	int		w;
	int		h;
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
	if (!img_ptr)
		error_exit(game, "error : get_img()\n");
	if (w != 64 || h != 64)
		error_exit(game, "error : xpm img size is not 64x64\n");
	return (img_ptr);
}
