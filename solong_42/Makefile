NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
INC_DIR	= ./include/
LIBFT_DIR	= ./lib_42/libft/
GNL_DIR		= ./lib_42/gnl/
MLX_DIR		= ./minilibx_opengl/
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

LFT_A		= libft.a
GNL_A		= libgnl.a
MLX_A		= libmlx.a
SRCS_DIR	= ./src/

SRCS_FILE	=	check_compone.c \
				check_file.c \
				check_map.c \
				draw_compone.c \
				draw_wall.c \
				exit.c \
				free.c \
				init_game_etc.c \
				init_game.c \
				main.c \
				make_collec.c \
				make_map.c \
				moving.c \
				put_image.c	\
				utils.c \

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILE))

all : $(NAME)

$(NAME) :
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	mv $(LIBFT_DIR)$(LFT_A) $(LFT_A)
	mv $(GNL_DIR)$(GNL_A) $(GNL_A)
	cp $(MLX_DIR)$(MLX_A) $(MLX_A)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) \
	-I $(INC_DIR) \
	$(LFT_A) $(GNL_A) \
	$(MLX_FLAGS)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	rm -rf $(LFT_A)
	rm -rf $(GNL_A)
	rm -rf $(MLX_A)

fclean : clean
	rm -rf $(NAME)

re : fclean all

PHONY : all clean fclean re