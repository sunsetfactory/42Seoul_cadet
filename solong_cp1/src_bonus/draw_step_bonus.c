#include "../include/so_long.h"

void	draw_step(t_game *game)
{
	char	*str;

	str = ft_itoa(game->step);
	put_img(game, game->img.step_bg, 0, 0);
	mlx_string_put(game->mlx, game->win, 40, 40, 0xFFFFFF, str);
	free(str);
}
