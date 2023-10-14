NAME=libft.a

CC=cc

CFLAG=-Wall -Wextra -Werror

RM=rm -rf

SRC_MAIN=ft_calloc.c  ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRC_BONUS=ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c
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
