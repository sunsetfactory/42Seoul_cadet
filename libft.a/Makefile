NAME=libft.a

CC=gcc
CFLAG=-Wall -Wextra -Werror

RM=rm -rf

SRCS=${wildcard *.c}

OBJS=$(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rc $@ $^

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re