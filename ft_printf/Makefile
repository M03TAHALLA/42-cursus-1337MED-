NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c base_nbr.c ft_putstr.c ft_strlen.c ft_putadd.c ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re all