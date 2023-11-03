#include "../include/so_long.h"

void	choice_enemy_img(t_game *game)
{
	if (game->enemy.dir == RIGHT)
		game->enemy.chosen_img = game->img.enemy_r;
	else if (game->enemy.dir == LEFT)
		game->enemy.chosen_img = game->img.enemy_l;
}

int	wall_check_enemy(t_game *game)
{
	int	row2;
	int	col2;

	row2 = game->enemy.row2;
	col2 = game->enemy.col2;
	if (game->map.data[row2][col2] == '1')
		return (1);
	return (0);
}

int	exit_check_enemy(t_game *game)
{
	int	row2;
	int	col2;

	row2 = game->enemy.row2;
	col2 = game->enemy.col2;
	if (game->map.data[row2][col2] == 'E')
		return (1);
	return (0);
}

int	collec_check_enemy(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = game->enemy.col2;
	y = game->enemy.row2;
	i = -1;
	while (game->collec[++i])
	{
		if (game->collec[i]->col == x && game->collec[i]->row == y
			&& game->collec[i]->get == 0)
			return (1);
	}
	return (0);
}

void	set_row2_col2(t_game *game)
{
	if (game->enemy.dir == RIGHT)
		game->enemy.col2++;
	if (game->enemy.dir == LEFT)
		game->enemy.col2--;
	if (game->enemy.dir == DOWN)
		game->enemy.row2++;
	if (game->enemy.dir == UP)
		game->enemy.row2--;
}
