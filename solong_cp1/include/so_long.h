#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h> // usleep();
# include <stdlib.h> // malloc() exit()
# include <fcntl.h> // open()
# include "../lib_42/libft/libft.h" // ft_putstr_fd()
# include "../lib_42/gnl/get_next_line.h"
# include "../minilibx_opengl/mlx.h"

# define FILE_NAME_EXTENSION ".ber"
# define TILE_SIZE 64
# define IMG_PATH "/Users/jinglee/42/jinglee/asset/"
# define IMG_PATH_WALL "/Users/jinglee/42/jinglee/asset/wall/"
# define IMG_PATH_PLAYER "/Users/jinglee/42/jinglee/asset/player/"
# define IMG_PATH_EXIT "/Users/jinglee/42/jinglee/asset/exit/"
# define IMG_PATH_ENEMY "/Users/jinglee/42/jinglee/asset/enemy/"

// version
# define MANDATORY	0
# define BONUS		1

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

// direction
# define RIGHT	1
# define LEFT 	2
# define UP		3
# define DOWN	4

//color
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define SKY "\x1b[36m"
# define RESET "\x1b[0m"

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

typedef struct s_enemy
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
}	t_enemy;

typedef struct s_num
{
	int		collec;
	int		player;
	int		exit;
	int		enemy;
}	t_num;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			state;
	t_num		num;
	t_player	player;
	t_enemy		enemy;
	t_collec	**collec;
	t_exit		exit;
	t_map		map;
	t_img		img;
	int			step;
	int			version;
}	t_game;

// ft_exit.c
void	error_exit(t_game *game, char *msg);
void	normal_exit(t_game *game);

// init
void	init_game_malloc_ptr(t_game *game);
void	init_game_mlx(t_game *game);
void	init_game_img(t_game *game);
void	init_game_state(t_game *game);
void	init_game_etc(t_game *game);
void	init_game_num(t_game *game);

// check_map.c
void	check_map(t_game *game, char *map_name);

// check_map_fts.c
void	check_rec_and_get_row_col(t_game *game, char *map_name);
void	check_wall_leak(t_game *game);

// check_filename.c
void	check_filename(t_game *game, char *filename);

// check_compo.c
void	check_compo(t_game *game);

// make_map.c
void	make_map(t_game *game, char *map_name);
void	make_collec_list(t_game *game);

// draw_
void	draw_wall(t_game *game);
void	draw_tile(t_game *game);
void	draw_compo(t_game *game);
void	draw_exit(t_game *game);
void	draw_collec(t_game *game);
void	draw_player(t_game *game);

// move_player.c
void	move_player(t_game *game, int dir);

//move_utils.c
void	choice_player_img(t_game *game, int dir);
int		wall_check(t_game *game);
int		exit_check(t_game *game);
void	collec_check(t_game *game);

// util.c
int		ft_open_file(t_game *game, char *map_name);
void	free_map_data(t_game *game);
void	free_collec_list(t_game *game);
void	print_map_data(t_game *game);
void	print_collec(t_game *game);
void	*get_img(t_game *game, char *file);
void	put_img(t_game *game, void *img, int x, int y);

//=====================BONUS==============================

//check_compo_b
void	check_compo_bonus(t_game *game);

//move_utils_bonus.c
void	choice_enemy_img(t_game *game);
int		wall_check_enemy(t_game *game);
int		exit_check_enemy(t_game *game);
int		collec_check_enemy(t_game *game);
void	set_row2_col2(t_game *game);

//move_utils2_b
void	get_dir(t_game *game);
void	set_enemy_route(t_game *game);
void	change_dir(t_game *game);
void	reset_enemy_route(t_game *game);
void	check_catch_player(t_game *game);

// move_enemy_b.c
void	move_enemy(t_game *game);

// draw_enemy_b.c
void	draw_enemy(t_game *game);

// draw_step_b.c
void	draw_step(t_game *game);

// set_compo_val_b.c
void	set_compo_val_b(t_game *game);

#endif
