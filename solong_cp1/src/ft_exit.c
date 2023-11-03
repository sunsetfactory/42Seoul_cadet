#include "../include/so_long.h"

void	error_exit(t_game *game, char *msg)
{
	free_map_data(game);
	free_collec_list(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_putstr_fd(RED "-------------------------\n ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("-------------------------\n" RESET, 2);
	exit(1);
}

void	normal_exit(t_game *game)
{
	free_map_data(game);
	free_collec_list(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_putstr_fd(GREEN "--------------------\n", 1);
	ft_putstr_fd("  game termination\n", 1);
	ft_putstr_fd("--------------------\n" RESET, 1);
	exit(0);
}
