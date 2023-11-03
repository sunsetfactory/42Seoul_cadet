#include "../include/so_long.h"

void	draw_enemy(t_game *game)
{
	int		x;
	int		y;
	int		m_cnt;
	void	**img;

	x = game->enemy.pixel_x;
	y = game->enemy.pixel_y;
	m_cnt = game->enemy.move_cnt;
	img = game->enemy.chosen_img;
	if (m_cnt >= 0 && m_cnt < 8)
		put_img(game, img[0], x, y);
	else if (m_cnt >= 8 && m_cnt < 16)
		put_img(game, img[1], x, y);
	else if (m_cnt >= 16 && m_cnt < 24)
		put_img(game, img[2], x, y);
	else if (m_cnt >= 24 && m_cnt < 32)
		put_img(game, img[0], x, y);
}
