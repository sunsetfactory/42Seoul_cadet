/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:57:41 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/01 16:05:18 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_info *p)
{
	if (keycode == UP_W && p->play_y != 0)
		p->play_y -= p->img_y;
	if (keycode == DOWN_S && p->play_y != 480)
		p->play_y += p->img_y;
	else if (keycode == LEFT_A && p->play_x != 0)
		p->play_x -= p->img_x;
	else if (keycode == RIGHT_D && p->play_x != 480)
		p->play_x += p->img_x;
	else if (keycode == EXIT_ESC)
		exit(0);
	else if (keycode == EXIT_BUTTON)
		exit(0);
	printf("x: %d y : %d\n", p->play_x, p->play_y);
	return (0);
}

int	draw(t_info *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->c, p->play_x, p->play_y);
	return (0);
}

int	main(void)
{
	t_info		info;

	info.mlx = init_mlx();
	info.win = new_window_mlx(info, 1000, 1000, "DrawMap");
	if (init(&info) == -1)
		return (0);
	printf("map comple %d\n", make_map(&info));
	info.c = make_image(info, PIKA_XPM, &info.img_x, &info.img_y);
	info.play_x = 0;
	info.play_y = 0;
	mlx_key_hook(info.win, &key_press, &info);
	mlx_loop_hook(info.mlx, &draw, &info);
	mlx_loop(info.mlx);
	return (0);
}
