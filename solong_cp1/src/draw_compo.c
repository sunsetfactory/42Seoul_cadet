#include "../include/so_long.h"

void	draw_exit_opening(t_game *game, int m_cnt, int x, int y)
{
	if (m_cnt >= 0 && m_cnt < 8)
		put_img(game, game->img.exit[1], x, y);
	else if (m_cnt >= 8 && m_cnt < 16)
		put_img(game, game->img.exit[2], x, y);
	else if (m_cnt >= 16 && m_cnt < 24)
		put_img(game, game->img.exit[3], x, y);
	else if (m_cnt >= 24 && m_cnt < 32)
		put_img(game, game->img.exit[4], x, y);
	game->exit.move_cnt++;
	if (game->exit.move_cnt >= 31)
	{
		game->exit.move_cnt = 0;
		game->exit.state = OPEN;
	}
}

void	draw_exit(t_game *game)
{
	int	x;
	int	y;
	int	m_cnt;

	m_cnt = game->exit.move_cnt;
	x = game->exit.col * TILE_SIZE;
	y = game->exit.row * TILE_SIZE;
	put_img(game, game->img.exit[0], x, y);
	if (game->exit.state == OPEN)
		put_img(game, game->img.exit[4], x, y);
	else if (game->exit.state == CLOSE)
		put_img(game, game->img.exit[1], x, y);
	else if (game->exit.state == OPENING)
		draw_exit_opening(game, m_cnt, x, y);
}

void	draw_collec(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	if (game->collec)
	{
		while (game->collec[++i])
		{
			if (game->collec[i]->get == 0)
			{
				x = game->collec[i]->col * TILE_SIZE;
				y = game->collec[i]->row * TILE_SIZE;
				put_img(game, game->img.collec, x, y);
			}
		}
	}
}

void	draw_compo(t_game *game)
{
	draw_collec(game);
	draw_exit(game);
}
