NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c \
       pathes.c main.c checkinfile.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY :  all re clean fclean
