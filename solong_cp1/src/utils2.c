#include "../include/so_long.h"

void	print_map_data(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.data[i])
	{
		printf("[%d] %s\n", i, game->map.data[i]);
		i++;
	}
}

void	print_collec(t_game *game)
{
	int	i;

	i = 0;
	while (game->collec[i])
	{
		printf("collec[%d] (%d, %d) - get : (%d)\n", i, game->collec[i]->row,
			game->collec[i]->col, game->collec[i]->get);
		i++;
	}
}
