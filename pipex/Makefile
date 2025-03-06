NAME = pipex
CC = cc
SRC = src/pipex.c src/include/utils/ft_split.c src/include/utils/ft_strnstr.c src/include/utils/ft_strjoin.c src/include/utils/ft_strlen.c src/include/utils/ft_split_args.c src/pipex_utils2.c  \
		src/include/utils/ft_strlcpy.c src/pipex_utils.c src/include/utils/split_args_utils.c src/pipex_utils1.c src/include/utils/ft_strcmp.c
SRC_BONUS = bonus/pipex_bonus.c bonus/include/utils/ft_split_bonus.c bonus/include/utils/ft_strnstr_bonus.c bonus/include/utils/ft_strjoin_bonus.c bonus/include/utils/ft_strlen_bonus.c bonus/include/utils/ft_split_args_bonus.c  \
			bonus/include/utils/ft_strlcpy_bonus.c bonus/pipex_utils_bonus.c bonus/include/utils/split_args_utils_bonus.c bonus/pipex_utils1_bonus.c bonus/include/utils/ft_strcmp_bonus.c
HEADERS = src/include/pipex.h src/include/utils/utils.h 
HEADERS_BONUS = bonus/include/pipex_bonus.h bonus/include/utils/utils_bonus.h
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@rm -f $(OBJ_BONUS) .bonus
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: .bonus

.bonus: $(OBJ_BONUS) $(HEADERS_BONUS)
	@rm -rf $(OBJ)
	@touch .bonus
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)

$(OBJ): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS): %.o: %.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus