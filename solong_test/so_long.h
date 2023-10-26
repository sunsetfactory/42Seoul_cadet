/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:12:22 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/26 22:26:25 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx_opengl_20191021/mlx.h"

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
}	t_info;

# define PIKA_XPM	"img/pikachu.xpm"

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

#endif