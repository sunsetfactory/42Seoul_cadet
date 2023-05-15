NAME=libftprintf.a

CC=cc

CFLAG=-Wall -Wextra -Werror

RM=rm -rf

SRC_MAIN=ft_printf.c ft_pr_gate.c
OBJ_O=$(SRC_MAIN:.c=.o)

$(NAME) : $(OBJ_O)
	ar rsc $(NAME) $^
	touch $@

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@

clean :
	$(RM) $(OBJ_O)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean 
	make all

.PHONY : all clean fclean re
