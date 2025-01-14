# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 10:53:07 by mtahalla          #+#    #+#              #
#    Updated: 2025/01/11 10:53:07 by mtahalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = /Users/mtahalla/Desktop/
HEADER = /include/so_long.h
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
MLX_FLAGS = -L$(LIB) -lmlx -lm -framework OpenGL -framework AppKit
SRC = src/main.c src/map.c src/game.c src/render.c src/input.c src/ft_strcpyline.c src/map_checker.c src/map_checker2.c src/map_checker3.c src/enemy_animate.c LIBFT/ft_strchr.c LIBFT/ft_strdup.c LIBFT/ft_strtrim.c LIBFT/ft_itoa.c LIBFT/ft_strjoin.c LIBFT/ft_strlcpy.c LIBFT/ft_strlen.c LIBFT/ft_memcpy.c LIBFT/ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/base_nbr.c ft_printf/ft_putstr.c ft_printf/ft_strlen_printf.c ft_printf/ft_putadd.c ft_printf/ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) include/so_long.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re