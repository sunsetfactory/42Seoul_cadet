# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 02:00:06 by seokjyan          #+#    #+#              #
#    Updated: 2023/10/15 04:52:03 by seokjyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Werror

RM = rm -rf

NAME=server
NAME2=client

NAME_BONUS = server_bonus
NAME_BONUS2 = client_bonus

LIBFT_DIR=./libft/
LIBFT=libft.a

SRCS = server.c
SRCS2 = client.c
SRCS_BONUS = server_bonus.c
SRCS_BONUS2 = client_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS2 = $(SRCS2:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%_bonus.c=%.o)
OBJS_BONUS2 = $(SRCS_BONUS2:%_bonus.c=%.o)

all: $(LIBFT) $(NAME) $(NAME2)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAG) $(OBJS2) $(LIBFT) -o $(NAME2)

bonus: $(NAME_BONUS) $(NAME_BONUS2)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAG) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(NAME_BONUS2): $(OBJS_BONUS2)
	$(CC) $(CFLAG) $(OBJS_BONUS2) $(LIBFT) -o $(NAME_BONUS2)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS2)
	$(RM) $(OBJS_BONUS)
	$(RM) $(OBJS_BONUS2)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)
	$(RM) $(NAME2)
	$(RM) $(NAME_BONUS)
	$(RM) $(NAME_BONUS2)

re: fclean all

.PHONY: all clean fclean re