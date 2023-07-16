NAME=getnextline.a

CC=cc

CFLAG=-Wall -Wextra -Werror

RM=rm -rf

SRC_MAIN=
SRC_BONUS=
OBJ_O=$(SRC_MAIN:.c=.o)
OBJ_B=$(SRC_BONUS:_bonus.c=.o)

$(NAME) : $(OBJ_O)
	ar rsc $(NAME) $^
	touch $@

bonus : $(OBJ_B)
	ar rcs $(NAME) $^
	touch $@

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@

%.o : %_bonus.c
	$(CC) $(CFLAG) -c $^ -o $@

clean :
	$(RM) $(OBJ_O) $(OBJ_B)

fclean : clean
	$(RM) $(NAME) bonus

re : 
	make fclean 
	make all

.PHONY : all clean fclean re
