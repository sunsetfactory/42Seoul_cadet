CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS 	= ./get_next_line.c\

OBJS 	= $(SRCS:.c=.o)

NAME	= libgnl.a

all 	: $(NAME)

$(NAME) : $(OBJS)
	make -C ../libft
	cp ../libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)

clean 	:
	rm -f $(OBJS) $(BOBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean $(NAME)

