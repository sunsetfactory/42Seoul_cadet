NAME		= so_long
NAME_BONUS	= so_long_bonus
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
INCS_DIR	= ./include/
LIBFT_DIR	= ./lib_42/libft/
GNL_DIR		= ./lib_42/gnl/
MLX_DIR		= ./minilibx_opengl/
MLX_FLAGS	= -framework OpenGL -framework Appkit

SRCS_DIR	= ./src/
SRCS_DIR_B	= ./src_bonus/

SRC_MAIN	= $(SRCS_DIR)main.c
SRC_MAIN_B	= $(SRCS_DIR_B)main_bonus.c

SRCS_FILE	= 	check_compo.c \
			  	check_filename.c \
			  	check_map_fts.c \
			  	check_map.c \
			  	draw_compo.c \
			  	draw_player.c \
			  	draw_tile.c \
			  	draw_wall.c \
			  	ft_exit.c \
			  	init_game_img.c \
			  	init_game.c \
			  	make_collec.c \
			  	make_map.c \
			  	move_player.c \
			  	move_utils.c \
			  	utils.c \
			  	utils2.c \

SRCS_FILE_B = 	check_compo_bonus.c \
				draw_enemy_bonus.c \
				draw_step_bonus.c \
				move_enemy_bonus.c \
				move_utils_bonus.c \
				move_utils2_bonus.c \
				set_compo_val_bonus.c
			  

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILE))

SRCS_B		= $(addprefix $(SRCS_DIR_B), $(SRCS_FILE_B)) 

all 	: $(NAME)

$(NAME) :
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(SRC_MAIN) -o $(NAME) \
	-I $(INCS_DIR) \
	-L $(LIBFT_DIR) -lft \
	-L $(GNL_DIR) -lgnl \
	-L $(MLX_DIR) -lmlx $(MLX_FLAGS)

$(NAME_BONUS) :
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_B) $(SRC_MAIN_B) -o $(NAME_BONUS) \
	-I $(INCS_DIR) \
	-L $(LIBFT_DIR) -lft \
	-L $(GNL_DIR) -lgnl \
	-L $(MLX_DIR) -lmlx $(MLX_FLAGS)

bonus : $(NAME_BONUS)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean : clean
	rm -rf $(NAME) $(NAME).dSYM
	rm -rf $(NAME_BONUS) $(NAME_BONUS).dSYM

re : fclean all

PHONY : all clean fclean re bonus