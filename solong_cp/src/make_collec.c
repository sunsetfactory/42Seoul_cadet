#include "../include/so_long.h"

void	make_collec_list(t_game *game)
{
	int	i;

	game->collec = (t_collec **)malloc(sizeof(t_collec *)
			* (game->num.collec + 1));
	i = -1;
	while (++i < game->num.collec)
	{
		game->collec[i] = (t_collec *)malloc(sizeof(t_collec));
	}
	game->collec[i] = NULL;
}
