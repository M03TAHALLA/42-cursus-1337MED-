# Variables
GREEN = \033[0;32m
RED = \033[0;31m
CC = cc
LIBFT_DIR = libft
CGFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L/goinfre/$(USER)/homebrew/opt/readline/lib -Ofast  

LDLIBS = -lreadline

NUM_LIBFT = libft.a

$(NUM_LIBFT)/%.o: $(LIBFT_DIR)/%.c
	make -C $(LIBFT_DIR) $<

LIBFT_SRCS = ft_isalpha.c ft_strndup.c ft_strcpy.c ft_strncpy.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strcat.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c
LIBFT_OBJS = libft/ft_isalpha.o libft/ft_isdigit.o libft/ft_strndup.o libft/ft_strcpy.o libft/ft_strncpy.o libft/ft_isalnum.o libft/ft_isascii.o libft/ft_strcat.o libft/ft_isprint.o libft/ft_strlen.o libft/ft_memset.o libft/ft_bzero.o libft/ft_memcpy.o libft/ft_memmove.o libft/ft_strlcpy.o libft/ft_strlcat.o libft/ft_toupper.o libft/ft_tolower.o libft/ft_strchr.o libft/ft_strrchr.o libft/ft_strncmp.o libft/ft_memchr.o libft/ft_memcmp.o libft/ft_strnstr.o libft/ft_atoi.o libft/ft_calloc.o libft/ft_strdup.o libft/ft_substr.o libft/ft_strjoin.o libft/ft_strtrim.o libft/ft_split.o libft/ft_itoa.o libft/ft_strmapi.o libft/ft_striteri.o libft/ft_putchar_fd.o libft/ft_putstr_fd.o libft/ft_putendl_fd.o libft/ft_putnbr_fd.o libft/ft_strcmp.o
LIBFT = $(LIBFT_DIR)/$(NUM_LIBFT)
SRCS = mandatory/minishell.c mandatory/src/parsing/make_algo_stacks.c mandatory/src/parsing/make_tree.c mandatory/src/parsing/make_list.c mandatory/src/parsing/tokenizer.c mandatory/src/parsing/syntax_error.c mandatory/src/execution/pipe/pipex.c mandatory/src/execution/pipe/utils/ft_split_pipe.c mandatory/src/execution/pipe/utils/ft_strnstr_pipe.c mandatory/src/execution/pipe/utils/ft_strjoin_pipe.c mandatory/src/execution/pipe/utils/ft_strlen_pipe.c mandatory/src/execution/pipe/utils/ft_split_args.c \
            mandatory/src/execution/pipe/utils/ft_strlcpy_pipe.c mandatory/src/execution/pipe/pipex_utils.c mandatory/src/execution/pipe/pipex_utils1.c mandatory/src/execution/pipe/pipex_utils2.c mandatory/src/execution/pipe/execution.c mandatory/src/execution/pipe/execution2.c mandatory/src/execution/pipe/execution3.c mandatory/src/execution/pipe/execution4.c mandatory/src/execution/pipe/execution5.c mandatory/src/execution/pipe/utils/split_args_utils.c mandatory/src/execution/pipe/utils/ft_strcmp_pipe.c \
            mandatory/src/execution/cmd/execution.c mandatory/src/execution/cmd/execution_utils.c mandatory/src/execution/cmd/execution_utils1.c mandatory/src/execution/cmd/execution_utils2.c mandatory/src/execution/logical_op/execution.c mandatory/src/execution/redirection/execution.c mandatory/src/execution/redirection/execution2.c mandatory/src/execution/redirection/execution3.c mandatory/src/execution/redirection/execution4.c \
            mandatory/src/my_env.c mandatory/src/signals/signals_handler.c mandatory/src/execution/redirection/here_doc.c mandatory/src/execution/redirection/here_doc2.c mandatory/src/execution/redirection/here_doc_utils.c mandatory/src/execution/redirection/here_doc_utils2.c \
            mandatory/src/execution/built_in/builtin.c mandatory/src/execution/built_in/echo.c mandatory/src/execution/built_in/cd.c mandatory/src/execution/built_in/pwd.c mandatory/src/execution/built_in/env.c mandatory/src/execution/built_in/exit.c \
            mandatory/src/execution/built_in/utils/cd_utils.c mandatory/src/execution/built_in/utils/cd_utils2.c mandatory/src/execution/built_in/utils/expand.c mandatory/src/execution/built_in/utils/expand_utils.c mandatory/src/execution/built_in/utils/exit_utils.c mandatory/src/execution/built_in/utils/env_utils.c mandatory/src/execution/built_in/utils/env_utils2.c mandatory/src/execution/built_in/unset.c mandatory/src/execution/built_in/export.c \
            mandatory/src/execution/built_in/utils/export_utils.c mandatory/src/execution/built_in/utils/export_utils2.c mandatory/src/execution/built_in/utils/export_utils3.c mandatory/src/execution/built_in/utils/export_utils4.c mandatory/src/execution/built_in/utils/export_utils5.c \
            mandatory/src/wild_cards/wild_card.c mandatory/src/parsing/tokenizer_help.c mandatory/src/parsing/syntax_error_help.c mandatory/src/parsing/syntax_error_help_2.c mandatory/src/parsing/syntax_error_help_3.c mandatory/src/parsing/make_stack_algo_help.c mandatory/src/parsing/make_list_help.c mandatory/src/parsing/make_list_help_2.c mandatory/src/wild_cards/wild_card_help.c mandatory/minishell_help.c
SRCS_BONUS = bonus/minishell_bonus.c bonus/src/parsing/make_algo_stacks_bonus.c bonus/src/parsing/make_tree_bonus.c bonus/src/parsing/make_list_bonus.c bonus/src/parsing/tokenizer_bonus.c bonus/src/parsing/syntax_error_bonus.c bonus/src/execution/pipe/pipex_bonus.c bonus/src/execution/pipe/utils/ft_split_pipe_bonus.c bonus/src/execution/pipe/utils/ft_strnstr_pipe_bonus.c bonus/src/execution/pipe/utils/ft_strjoin_pipe_bonus.c bonus/src/execution/pipe/utils/ft_strlen_pipe_bonus.c bonus/src/execution/pipe/utils/ft_split_args_bonus.c  \
            bonus/src/execution/pipe/utils/ft_strlcpy_pipe_bonus.c bonus/src/execution/pipe/pipex_utils_bonus.c bonus/src/execution/pipe/pipex_utils1_bonus.c bonus/src/execution/pipe/pipex_utils2_bonus.c bonus/src/execution/pipe/execution_bonus.c bonus/src/execution/pipe/execution2_bonus.c bonus/src/execution/pipe/execution3_bonus.c bonus/src/execution/pipe/execution4_bonus.c  bonus/src/execution/pipe/execution5_bonus.c bonus/src/execution/pipe/utils/split_args_utils_bonus.c bonus/src/execution/pipe/utils/ft_strcmp_pipe_bonus.c \
            bonus/src/execution/cmd/execution_bonus.c bonus/src/execution/cmd/execution_utils_bonus.c bonus/src/execution/cmd/execution_utils1_bonus.c bonus/src/execution/cmd/execution_utils2_bonus.c bonus/src/execution/logical_op/execution_bonus.c bonus/src/execution/redirection/execution_bonus.c bonus/src/execution/redirection/execution2_bonus.c bonus/src/execution/redirection/execution3_bonus.c bonus/src/execution/redirection/execution4_bonus.c \
            bonus/src/my_env_bonus.c bonus/src/signals/signals_handler_bonus.c bonus/src/execution/redirection/here_doc_bonus.c bonus/src/execution/redirection/here_doc2_bonus.c bonus/src/execution/redirection/here_doc_utils_bonus.c bonus/src/execution/redirection/here_doc_utils2_bonus.c \
            bonus/src/execution/built_in/builtin_bonus.c bonus/src/execution/built_in/echo_bonus.c bonus/src/execution/built_in/cd_bonus.c bonus/src/execution/built_in/pwd_bonus.c bonus/src/execution/built_in/env_bonus.c bonus/src/execution/built_in/exit_bonus.c \
            bonus/src/execution/built_in/utils/cd_utils_bonus.c bonus/src/execution/built_in/utils/cd_utils2_bonus.c bonus/src/execution/built_in/utils/expand_bonus.c bonus/src/execution/built_in/utils/expand_utils_bonus.c bonus/src/execution/built_in/utils/exit_utils_bonus.c bonus/src/execution/built_in/utils/env_utils_bonus.c bonus/src/execution/built_in/utils/env_utils2_bonus.c bonus/src/execution/built_in/unset_bonus.c bonus/src/execution/built_in/export_bonus.c \
            bonus/src/execution/built_in/utils/export_utils_bonus.c bonus/src/execution/built_in/utils/export_utils2_bonus.c bonus/src/execution/built_in/utils/export_utils3_bonus.c bonus/src/execution/built_in/utils/export_utils4_bonus.c bonus/src/execution/built_in/utils/export_utils5_bonus.c \
            bonus/src/wild_cards/wild_card_bonus.c bonus/src/parsing/tokenizer_help_bonus.c  bonus/src/parsing/syntax_error_help_bonus.c bonus/src/parsing/syntax_error_help_2_bonus.c bonus/src/parsing/syntax_error_help_3_bonus.c bonus/src/parsing/make_stack_algo_help_bonus.c bonus/src/parsing/make_list_help_bonus.c bonus/src/parsing/make_list_help_2_bonus.c bonus/src/wild_cards/wild_card_help_bonus.c bonus/minishell_help_bonus.c
			
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
EXEC = minishell
EXEC_BONUS = minishell_bonus

all: $(LIBFT) $(EXEC)
	@echo "$(GREEN)building complete"

$(LIBFT): $(LIBFT_OBJS)
	@ar rcs $@ $^

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CGFLAGS) -c $< -o $@

$(EXEC): $(OBJS) $(LIBFT)
	$(CC) $(CGFLAGS) $(OBJS) $(LDLIBS) $(LIBFT) -o $@

bonus: $(LIBFT) $(EXEC_BONUS)
	echo "$(GREEN)bonus build complete"

$(EXEC_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDLIBS) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CGFLAGS) -c $< -o $@

clean:
	rm -f $(LIBFT_OBJS) $(OBJS) $(OBJS_BONUS)
	@echo "$(RED)clean complete"

fclean: clean
	@rm -f $(LIBFT) $(EXEC) $(EXEC_BONUS)

re: fclean all

.PHONY: all clean fclean bonus re