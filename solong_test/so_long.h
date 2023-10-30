/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:12:22 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/30 16:29:44 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx_opengl_20191021/mlx.h"

typedef struct s_map
{
	void	*tile;
	void	*wall;
	void	*jiu;
	void	*ball;
}	t_map;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*c;
	int		fd;
	int		play_x;
	int		play_y;
	int		img_x;
	int		img_y;
	int		win_x;
	int		win_y;
	t_map	map;
}	t_info;

# define PIKA_XPM	"img/pikachu.xpm"
# define GOJIJI_XPM	"img/ggojiji.xpm"
# define JIU_XPM	"img/jiu.xpm"
# define TILE_XPM	"img/tile.xpm"
# define BALL_XPM	"img/ball.xpm"

# define UP_W				13
# define DOWN_S				1
# define LEFT_A				0
# define RIGHT_D			2
# define EXIT_ESC			53
# define EXIT_BUTTON		17

// handling_return.c
void	*init_mlx(void);
void	*new_window_mlx(t_info info, int x, int y, char *c);
void	*make_image(t_info info, char *c, int *x, int *y);
int		init(t_info *info);
int		make_map(t_info *info);

#endif