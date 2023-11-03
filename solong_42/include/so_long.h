/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:59:26 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/03 19:20:01 by seokjyan         ###   ########.fr       */
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

# define FILE_NAME_EXTENSION ".ber"
# define TILE_SIZE 64
# define IMG_PATH "./asset/"

// state (game, player, exit)
# define PLAYING	1
# define END		0

# define STANDING	1
# define WALKING	2

# define OPEN		0
# define CLOSE		1
# define OPENING	2


// key
# define X_EVENT_KEY_PRESS	2
# define KEY_ESC 	53
# define KEY_W 		13 
# define KEY_A 		0
# define KEY_S 		1
# define KEY_D 		2
# define KEY_UP		126
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124


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
	void	*sprite_r;
	void	*sprite_l;
	void	*collec;
	void	*exit;

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
	void	*chosen_img;
}	t_player;

typedef struct s_num
{
	int		player;
	int		collec;
	int		exit;
}	t_num;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			state;
	t_player	player;
	t_collec	**collec;
	t_exit		exit;
	t_num		num;
	t_map		map;
	t_img		img;
	int			step;
	int			version;
}	t_game;

// check_compone.c
void	check_compo(t_game *game);

// check_file.c
void	check_filename(t_game *game, char *filename);

// check_map.c
void	check_map(t_game *game, char *map_name);

// draw_map.c
void	draw_wall(t_game *game);

// draw_compone.c
void	draw_player(t_game *game);
void	draw_compo(t_game *game);
void	draw_tile(t_game *game);

// draw_wall.c
void	draw_wall(t_game *game);

// free.c
void	free_map_data(t_game *game);
void	free_collec_list(t_game *game);

//init_game_etc.c
void	init_game_etc(t_game *game);

// init_game.c
void	init_game_num(t_game *game);
void	init_game_malloc_ptr(t_game *game);

// make_collec.c
void	make_collec_list(t_game *game);

// make_map.c
void	make_map(t_game *game, char *map_name);

// put_image.c
void	put_img(t_game *game, void *img, int x, int y);

// utils.c
int		ft_open_file(t_game *game, char *map_name);

#endif
