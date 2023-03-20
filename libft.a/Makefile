NAME=libft.a
SRCS=${wildcard *.c}

OBJS=${SRCS:.c=.o}

HEAD = libft.h

CC= gcc
RM= rm -f

CFLAGS= -Wall -Wextra -Werror


$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}

.c.o:
		${CC} ${CFLAGS} -include ${HEAD} -c $< -o ${<:.c=.o}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all