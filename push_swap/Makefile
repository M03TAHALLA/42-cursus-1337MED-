NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = include/push_swap.h include/LIBFT/libft.h
HEADERS_BONUS = bonus/push_swap_bonus.h bonus/src/get_next_line/get_next_line_bonus.h
SRC = src/check_argument.c src/push_swap.c include/LIBFT/ft_atoi.c \
		include/LIBFT/ft_strchr.c include/LIBFT/ft_strlen.c \
		include/LIBFT/ft_isdigit.c include/LIBFT/ft_atol.c \
		src/check_argument_utils.c src/stack_utils.c src/moves_push.c \
		include/LIBFT/ft_split.c src/algo.c src/algo_min_number.c \
		src/algo_min_number_utils.c src/moves_reverse.c src/moves_rotate.c \
		src/moves_swap.c src/stack_utils2.c src/check_argument_utils2.c
SRCBONUS = 	bonus/src/check_argument_bonus.c bonus/src/push_swap_bonus.c include/LIBFT/ft_atoi.c \
			include/LIBFT/ft_strchr.c include/LIBFT/ft_strlen.c include/LIBFT/ft_strncmp.c \
			include/LIBFT/ft_isdigit.c include/LIBFT/ft_atol.c \
			bonus/src/check_argument_utils_bonus.c bonus/src/stack_utils_bonus.c bonus/src/moves_push_bonus.c \
			include/LIBFT/ft_split.c bonus/src/moves_reverse_bonus.c bonus/src/moves_rotate_bonus.c \
			bonus/src/moves_swap_bonus.c bonus/src/stack_utils2_bonus.c bonus/src/get_next_line/get_next_line_bonus.c \
			bonus/src/get_next_line/get_next_line_utils_bonus.c bonus/src/handle_moves_bonus.c bonus/src/check_argument_utils2_bonus.c


OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

OBJ_DIR_BONUS = bonus/obj
OBJ_BONUS = $(SRCBONUS:%.c=$(OBJ_DIR_BONUS)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_BONUS)

$(OBJ_DIR_BONUS)/%.o: %.c $(HEADERS_BONUS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -f $(OBJ_BONUS)
	rm -rf $(OBJ_DIR_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY : all clean re fclean bonus