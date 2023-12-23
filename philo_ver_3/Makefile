SRCS = main.c \
		utils.c \
		free.c \
		init.c \
		work.c \
		time.c
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBS = -lpthread

NAME= philo

all: $(NAME)

$(NAME): $(OBJS)
	gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} -g -fsanitize=thread

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
