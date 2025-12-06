/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:12:12 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:50:11 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_idx
{
	int	i;
	int	start;
	int	row;
}	t_idx;

# define TRUE 1
# define FALSE 0
# define T_NO 2
# define T_SO 3
# define T_WE 4
# define T_EA 5
# define T_C 6
# define T_F 7
# define WIN_WIDTH 1024
# define WIN_HEIGHT 640

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define KEY_RED 17
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef struct s_rc
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpdist;
	int		step_x;
	int		step_y;
	int		tex_num;
	int		side;
	int		tex_pos;
	double	dir_angle;
	double	fov;
}	t_rc;

typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	double	wall_hit_x;
}	t_draw;

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	esc;
}	t_key;

typedef struct s_img
{
	void	*img;
	int		texture_index;
	char	*addr;
	int		w;
	int		h;
	int		tex_x;
	int		tex_y;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_param
{
	t_mlx			*mlx;
	char			**world_map;
	char			*map_file_name;
	int				map_width;
	int				map_height;
	int				f_color[3];
	int				c_color[3];
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	t_img			*img;
	t_img			texs[4];
	t_rc			*rc;
}	t_param;

/* path_and_color.c */
void			put_path_and_color(char *line, t_param *param, int type);
void			find_path_and_color(char *line, t_param *param);

/* path.c */
void			find_path(char *line, t_param *param, int type);
void			path_check(t_param *param, int type);

/* color.c */
unsigned int	rgb_to_hex(int r, int g, int b);
void			color_check(t_param *param, int type);
void			find_color(char *line, t_param *param, int type, int i);

/* utils.c */
int				is_space(char c);
char			*mk_strdup(int start, int end, char *line);
int				count_line(char *line);
void			ft_free(char **arr);

/* mk_split.c */
void			allocate_and_set(int map_width, char **map, int *row);
char			*ft_strncpy(char *dest, const char *src, int n);
void			init_idx(t_idx *idx, char *line);
char			**mk_split(char *line, int map_width);

/* put_img.c */
void			put_img(t_param *param, int type, char *path);
void			put_addr(t_param *param);

/* read_and_copy.c */
void			read_map(t_param *param, int fd, char **line);
void			copy_map(t_param *param);
char			*read_line(int fd);
void			file_parsing(t_param *param);

/* map_parsing.c */
int				is_vaild_arg(char *file_name);
int				check_type(char *line);
void			error_check(t_param *param);
void			parse(t_param *param);

/* map_validation.c */
void			is_vaild(t_param *param, int new_h, int new_w);
int				check_char(t_param *param, int h, int w);
void			check_side(t_param *param, int h, int w);
void			check_player_pos(t_param *param, int h, int w);
void			check_space(t_param *param);

/* check_and_set.c */
void			set_ray(t_param *param, int x);
void			set_step_dist(t_param *param);
void			dda(t_param *param);
void			check_perp(t_param *param);
void			set_draw(t_param *param, t_draw *draw);

/* draw.c */
int				pick_texture(t_param *param);
void			set_texture(t_param *param, t_draw *draw);
void			wall_draw(t_param *param, t_draw *draw, t_img *t_data, int x);
void			clear_screen(t_param *param);

/* run.c */
void			raycasting(t_param *param, t_draw *draw, t_img *data);
int				main_loop(t_param *param);

/* hook.c */
void			move(double x, double y, t_param *param);
void			ray_hook(double rot_angle, t_param *param);
int				key_hook(int keycode, t_param *param);

void			ft_exit(char *txt);

/* utils_init.c */
void			init_rc(t_param *param);
void			init_param(t_param *param);
void			init_img(t_mlx *mlx, t_img *img);
void			init_key_status(t_param *param);
void			init_mlx(t_param *param);

#endif