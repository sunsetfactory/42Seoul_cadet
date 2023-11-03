#include "../include/so_long.h"

static void	count_compo_val(t_game *game, int r, int c)
{
	if (game->map.data[r][c] == 'P')
		game->num.player++;
	else if (game->map.data[r][c] == 'E')
		game->num.exit++;
	else if (game->map.data[r][c] == 'N')
		game->num.enemy++;
	else if (game->map.data[r][c] == 'C')
		game->num.collec++;
	if (game->num.player > 1 || game->num.exit > 1
		|| game->num.enemy > 1)
		error_exit(game, "error : player or "
			"exit or enemy number is over\n");
}

static void	count_compo(t_game *game)
{
	int	r;
	int	c;

	r = -1;
	while (++r < game->map.row)
	{
		c = -1;
		while (++c < game->map.col)
			count_compo_val(game, r, c);
	}
	if (game->num.player == 0 || game->num.exit == 0
		|| game->num.enemy == 0 || game->num.collec == 0)
		error_exit(game, "error : none 'P' or 'E' or 'C' or'N'\n");
}

void	check_compo_bonus(t_game *game)
{
	init_game_num(game);
	count_compo(game);
	make_collec_list(game);
	set_compo_val_b(game);
}
