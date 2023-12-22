CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
LIBS	= -lpthread

SRCS	= main.c init.c util.c print.c routine.c checker.c deallocate.c 

NAME	= philo

all : $(NAME)

$(NAME) :
	$(CC) ${CFLAGS} $(SRCS) -o $(NAME) ${LIBS} -g3 -fsanitize=thread

clean :
	rm $(NAME)

fclean :
	rm -rf $(NAME) $(NAME).dSYM

re : fclean $(NAME)

.PHONY : all clean fclean re