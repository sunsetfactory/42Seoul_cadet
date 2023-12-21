CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
LIBS	= -lpthread

SRCS	= main.c init.c util.c print.c routine.c checker.c deallocate.c 

NAME	= philo

all : $(NAME)

$(NAME) :
	$(CC) ${CFLAGS} $(SRCS) -o $(NAME) ${LIBS} -fsanitize=thread
clean :
	rm $(NAME)

fclean :
	rm -rf $(NAME) $(NAME).dSYM

re : fclean $(NAME)

.PHONY : all clean fclean re