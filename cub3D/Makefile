# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 22:16:34 by minkylee          #+#    #+#              #
#    Updated: 2024/02/29 15:54:48 by minkylee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = get_next_line/get_next_line.c\
        get_next_line/get_next_line_utils.c\
        main.c\
        parsing/map_parsing.c\
		parsing/map_validation.c\
		parsing/path_and_color.c\
		parsing/path.c\
		parsing/color.c\
		parsing/utils.c\
		parsing/mk_split.c\
		parsing/put_img.c\
		parsing/read_and_copy.c\
		parsing/utils_init.c\
		raycast/check_and_set.c\
		raycast/draw.c\
		raycast/hook.c\
		raycast/run.c

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
CFLAGS += -O3
SANITIZE = -fsanitize=address

%.o:%.c cub3d.h
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
		make -C ./mlx/
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

$(LIBFT):
		$(MAKE) -j -C ./libft

all: $(NAME)

clean:
		rm -rf $(OBJS)
		$(MAKE) -C ./libft clean

fclean: clean
		rm -rf $(NAME)
		$(MAKE) -C ./libft fclean

re:
		make fclean
		make all

.PHONY: all clean fclean re
