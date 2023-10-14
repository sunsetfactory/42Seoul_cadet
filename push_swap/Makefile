PUSH_SWAP=push_swap
NAME=$(PUSH_SWAP)

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

LIBFT_DIR=./libft/
LIBFT=libft.a

#SRCS=$(find . -name "*.c" ! -path "./libft/*")
SRCS=./$(PUSH_SWAP)_*/*.c
OBJS =$(SRCS:.c=.o)

$(NAME) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(PUSH_SWAP)
	touch $@

$(LIBFT) :
	make -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(LIBFT)

re : 
	make fclean 
	make all

.PHONY : all clean fclean re
