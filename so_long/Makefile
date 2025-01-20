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
NAME = so_long
CC = gcc
HEADERS = include/so_long.h LIBFT/libft.h get_next_line/get_next_line.h
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
MLX_FLAGS = -L$(LIB) -lmlx -framework OpenGL -framework AppKit
SRC = src/main.c src/map.c src/game.c src/render.c src/input.c src/ft_strcpyline.c src/map_checker.c src/map_checker2.c \
	  src/checker_player/checker.c src/checker_player/checker_util1.c src/checker_player/checker_util2.c src/enemy_animate.c LIBFT/ft_strchr.c LIBFT/ft_calloc.c LIBFT/ft_bzero.c \
	  LIBFT/ft_memset.c LIBFT/ft_strdup.c LIBFT/ft_itoa.c LIBFT/ft_strjoin.c LIBFT/ft_strlcpy.c \
	  LIBFT/ft_strlen.c LIBFT/ft_memcpy.c LIBFT/ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	  ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/base_nbr.c ft_printf/ft_putstr.c ft_printf/ft_strlen_printf.c \
	  ft_printf/ft_putadd.c ft_printf/ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re