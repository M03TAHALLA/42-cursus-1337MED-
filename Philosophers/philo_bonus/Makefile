NAME		= philo_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main_bonus.c init_bonus.c philo_routine_bonus.c simulation_bonus.c utils_bonus.c
OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re