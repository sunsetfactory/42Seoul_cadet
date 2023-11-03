#include "../include/so_long.h"

void	img_init_wall(t_game *game)
{
	game->img.wall_box = get_img(game, IMG_PATH_WALL "wall_BOX.xpm");
	game->img.wall_n = get_img(game, IMG_PATH_WALL "wall_N.xpm");
	game->img.wall_nw = get_img(game, IMG_PATH_WALL "wall_NW.xpm");
	game->img.wall_ne = get_img(game, IMG_PATH_WALL "wall_NE.xpm");
	game->img.wall_s = get_img(game, IMG_PATH_WALL "wall_S.xpm");
	game->img.wall_sw = get_img(game, IMG_PATH_WALL "wall_SW.xpm");
	game->img.wall_se = get_img(game, IMG_PATH_WALL "wall_SE.xpm");
	game->img.wall_w = get_img(game, IMG_PATH_WALL "wall_W.xpm");
	game->img.wall_e = get_img(game, IMG_PATH_WALL "wall_E.xpm");
}

void	img_init_sprite(t_game *game)
{
	game->img.sprite_r[0] = get_img(game, IMG_PATH_PLAYER "sprite_R1.xpm");
	game->img.sprite_r[1] = get_img(game, IMG_PATH_PLAYER "sprite_R2.xpm");
	game->img.sprite_r[2] = get_img(game, IMG_PATH_PLAYER "sprite_R3.xpm");
	game->img.sprite_r[3] = get_img(game, IMG_PATH_PLAYER "sprite_R4.xpm");
	game->img.sprite_r[4] = get_img(game, IMG_PATH_PLAYER "sprite_R5.xpm");
	game->img.sprite_r[5] = NULL;
	game->img.sprite_l[0] = get_img(game, IMG_PATH_PLAYER "sprite_L1.xpm");
	game->img.sprite_l[1] = get_img(game, IMG_PATH_PLAYER "sprite_L2.xpm");
	game->img.sprite_l[2] = get_img(game, IMG_PATH_PLAYER "sprite_L3.xpm");
	game->img.sprite_l[3] = get_img(game, IMG_PATH_PLAYER "sprite_L4.xpm");
	game->img.sprite_l[4] = get_img(game, IMG_PATH_PLAYER "sprite_L5.xpm");
	game->img.sprite_l[5] = NULL;
}

void	img_init_exit(t_game *game)
{
	game->img.exit[0] = get_img(game, IMG_PATH_EXIT "shutter0.xpm");
	game->img.exit[1] = get_img(game, IMG_PATH_EXIT "shutter1.xpm");
	game->img.exit[2] = get_img(game, IMG_PATH_EXIT "shutter2.xpm");
	game->img.exit[3] = get_img(game, IMG_PATH_EXIT "shutter3.xpm");
	game->img.exit[4] = get_img(game, IMG_PATH_EXIT "shutter4.xpm");
	game->img.exit[5] = NULL;
}

void	img_init_enemy(t_game *game)
{
	game->img.enemy_r[0] = get_img(game, IMG_PATH_ENEMY "enemy1_L.xpm");
	game->img.enemy_r[1] = get_img(game, IMG_PATH_ENEMY "enemy2_L.xpm");
	game->img.enemy_r[2] = get_img(game, IMG_PATH_ENEMY "enemy3_L.xpm");
	game->img.enemy_r[3] = NULL;
	game->img.enemy_l[0] = get_img(game, IMG_PATH_ENEMY "enemy1_L.xpm");
	game->img.enemy_l[1] = get_img(game, IMG_PATH_ENEMY "enemy2_L.xpm");
	game->img.enemy_l[2] = get_img(game, IMG_PATH_ENEMY "enemy3_L.xpm");
	game->img.enemy_l[3] = NULL;
}

void	init_game_img(t_game *game)
{
	game->img.tile = get_img(game, IMG_PATH "tile.xpm");
	game->img.collec = get_img(game, IMG_PATH "button.xpm");
	game->img.step_bg = get_img(game, IMG_PATH "step_bg.xpm");
	img_init_wall(game);
	img_init_sprite(game);
	img_init_exit(game);
	img_init_enemy(game);
	game->player.chosen_img = game->img.sprite_r;
	game->enemy.chosen_img = game->img.enemy_l;
}
