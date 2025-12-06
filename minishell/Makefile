# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 02:58:17 by minkylee          #+#    #+#              #
#    Updated: 2024/01/21 15:04:31 by seokjyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS =	./tokenizing/find_synerr.c \
		minishell.c \
		./tokenizing/pre_processing.c \
		./tokenizing/process_delimited.c \
		./tokenizing/process_dollar.c \
		./tokenizing/process_remove.c \
		./tokenizing/put_on_list.c \
		./tokenizing/search_dollar_env.c \
		./tokenizing/token_utils_two.c \
		./tokenizing/token_utils.c \
		./tokenizing/tokenize.c \
		./tokenizing/utils_quotes.c \
		./tokenizing/work_inside_quotes.c \
		./builtin/make_envp.c \
		./builtin/make_args.c \
		./builtin/ft_builtin.c \
		./builtin/ft_cd.c \
		./builtin/ft_echo.c \
		./builtin/ft_env.c \
		./builtin/ft_export.c \
		./builtin/ft_export_utils.c \
		./builtin/ft_pwd.c \
		./builtin/ft_unset.c \
		./builtin/ft_exit.c \
		./builtin/ft_execve.c \
		./redirection/exe_redirection.c \
		./redirection/ft_redirection.c \
		./child/child_process.c \
		./child/make_args_fork.c \
		./child/move_cmd.c \
		./child/about_fork.c \
		./heredoc/ft_heredoc.c \
		./heredoc/hdoc_utils.c \
		./heredoc/hdoc_utils2.c \
		./etc/run_command.c \
		./etc/path.c \
		./etc/get_env.c \
		./etc/signal.c \
		./etc/main_utils.c \
		./etc/free.c

OBJS = $(SRCS:.c=.o)
LIBFT = ./Libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./Libft -lft -lreadline

$(LIBFT):
	$(MAKE) -j -C ./Libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./Libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re
