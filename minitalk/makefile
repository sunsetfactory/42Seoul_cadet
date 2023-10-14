# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 02:00:06 by seokjyan          #+#    #+#              #
#    Updated: 2023/10/15 02:02:08 by seokjyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

CC = gcc -Wall -Werror -Wextra

RM = rm -rf

LIBFT = libft.a

LIB_DIR = ./libft/


all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) :
	$(MAKE) -C $(LIB_DIR)

$(SERVER) : 
	$(CC) server.c -o $@ -L$(LIB_DIR) -lft

$(CLIENT) : 
	$(CC) client.c -o $@ -L$(LIB_DIR) -lft

clean :
	$(MAKE) clean -C $(LIB_DIR)
	$(RM) *.o

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(SERVER) $(CLIENT)
	
re : 
	make fclean 
	make all

.PHONY : all clean fclean re
