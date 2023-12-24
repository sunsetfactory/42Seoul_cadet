NAME		= philo
	
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

FILES		= $(addprefix ./, get_time init_philos init join_free main msg routine checker utils usleep)

SRC			= $(FILES:=.c)
OBJ			= $(FILES:=.o)
PTHREAD		= -pthread

all: $(NAME)

$(NAME):  $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(PTHREAD) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(PTHREAD) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re
