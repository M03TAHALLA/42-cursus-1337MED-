/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:03:59 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/17 23:03:59 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include "src/wild_cards/wild_card.h"

typedef enum e_ast_type {
	AST_CMD,
	AST_PIPE,
	AST_AND,
	AST_OR,
	AST_REDIRECTION,
	AST_GROUP
}	t_ast_type;

typedef enum e_token_type {
	TOKEN_COMMAND,
	TOKEN_PIPE,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_PAREN_OPEN,
	TOKEN_PAREN_CLOSE
}	t_token_type;

# define MAX_FILES 1024

typedef struct s_redirection
{
	char					*file;
	t_token_type			type;
	int						heredoc_fd;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_tokens
{
	t_token_type			type;
	char					*cmd;
	t_redirection			*redirections;
	struct s_tokens			*next;
}							t_tokens;

typedef struct s_token_args
{
	t_tokens				*head;
	t_tokens				*current;
	t_tokens				*new_node;
	int						i;
}							t_token_args;

typedef struct s_stack
{
	t_tokens				*token;
	struct s_stack			*next;
}							t_stack;
typedef struct s_shuntin_yard_args
{
	t_stack					*output_queue;
	t_stack					*op_stack;
	t_tokens				*tmp;
}							t_sy__args;

typedef struct s_ast_node
{
	t_ast_type				type;
	struct s_ast_node		*left;
	struct s_ast_node		*right;
	char					**args;
	char					*cmd;
	char					**env;
	t_stack					*next;
	t_redirection			*redirections;
	int						has_pipe;
}							t_ast_node;
typedef struct s_node_stack
{
	t_ast_node				*node;
	struct s_node_stack		*next;
}							t_node_stack;

typedef struct main_args
{
	char					*line;
	char					**args;
	char					**my_env;
	t_stack					*stack;
	t_tokens				*tokens;
	t_ast_node				*ast;
	int						exit_status;
}							t_main_args;

char						**tokinize(char *line);
int							ft_isspace(char c);
int							skip_operator(char *line, int i);
int							count_tokens(char *line);
int							ft_is_red(char *str);
int							check_parentheses(char **args);
int							check_dquotes(char *str);
int							check_squotes(char *str);
void						print_error(char *str);
int							ft_is_op(char *str);
int							ft_is_cmd(char *arg);
int							ft_check_initial(char *str1, char *str2);
int							check_redirection(char **args, int i);
int							check_operator(char **args, int i);
int							check_open_paren(char **args, int i);
t_tokens					*ft_new_node(char *arg, int type);
void						put_redir(t_tokens *token, char *file,
								t_token_type type);
t_tokens					*tokens_list(char **args);
void						push(t_stack **stack, t_tokens *token);
t_tokens					*pop(t_stack **stack);
int							check_parentheses(char **args);
void						close_redirections(t_ast_node *node);
int							check_prio(t_tokens *token);
int							check_quotes(char *str);
void						handle_red(char **args, t_tokens **new_node);
int							build_cmd_str(char **args, t_tokens **new_node);
t_stack						*shuntin_yard(t_tokens *tokens);
t_ast_node					*make_tree(t_stack *stack);
bool						detect_pipe_in_ast(t_ast_node *node);
int							syntax_error(char **args);
char						**get_env(char **env);
void						free_ast(t_ast_node *node);
void						free_env1(char **env);
void						setup_signals(void);
void						prepare_all_heredocs(t_ast_node *root, char **envp,
								int *last_exit_status, bool has_pipe);
void						set_execution_mode(void);
void						set_interactive_mode(void);
void						restore_default_signals(void);
void						handle_signal(int sig);
int							help_dquote(char *str, int *i);
void						handle_hrdoc(int sig);
#endif