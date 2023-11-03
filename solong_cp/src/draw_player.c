#include "../include/so_long.h"

void	draw_player(t_game *game)
{
	int		x;
	int		y;
	int		m_cnt;
	void	**img;

	x = game->player.pixel_x;
	y = game->player.pixel_y;
	m_cnt = game->player.move_cnt;
	img = game->player.chosen_img;
	if (m_cnt >= 0 && m_cnt <= 2)
		put_img(game, img[0], x, y);
	else if (m_cnt >= 3 && m_cnt <= 5)
		put_img(game, img[1], x, y);
	else if (m_cnt >= 6 && m_cnt <= 8)
		put_img(game, img[2], x, y);
	else if (m_cnt >= 9 && m_cnt <= 11)
		put_img(game, img[3], x, y);
	else if (m_cnt >= 13 && m_cnt <= 15)
		put_img(game, img[4], x, y);
}
