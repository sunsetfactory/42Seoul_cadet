/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:59:26 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/01 18:06:00 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//color
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define SKY "\x1b[36m"
# define RESET "\x1b[0m"

# include <stdio.h>
# include <unistd.h> // usleep();
# include <stdlib.h> // malloc() exit()
# include <fcntl.h> // open()
# include "../lib_42/libft/libft.h" // ft_putstr_fd()
# include "../lib_42/gnl/get_next_line.h"
# include "../minilibx_opengl/mlx.h"


typedef struct s_map
{
	char	**data;
	int		col;
	int		row;
}	t_map;

typedef struct s_img
{
	void	*tile;
	void	*step_bg;
	void	*wall_box;
	void	*wall_n;
	void	*wall_nw;
	void	*wall_ne;
	void	*wall_s;
	void	*wall_sw;
	void	*wall_se;
	void	*wall_w;
	void	*wall_e;
	void	*sprite_r[6];
	void	*sprite_l[6];
	void	*enemy_r[4];
	void	*enemy_l[4];
	void	*collec;
	void	*exit[6];

}	t_img;

typedef struct s_collec
{
	int		get;
	int		col;
	int		row;
}	t_collec;

typedef struct s_exit
{
	int		state;
	int		col;
	int		row;
	int		move_cnt;
}	t_exit;

typedef struct s_player
{
	int		state;
	int		dir;
	int		pixel_x;
	int		pixel_y;
	int		col1;
	int		col2;
	int		row1;	
	int		row2;
	int		move_cnt;
	void	**chosen_img;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_collec	**collec;
	t_exit		exit;
	t_map		map;
	t_img		img;
	int			step;
	int			version;
}	t_game;

#endif