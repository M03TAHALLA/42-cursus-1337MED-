/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:37:18 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/23 13:32:00 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "src/execution/cmd/cmd_bonus.h"
#include "src/execution/logical_op/op_bonus.h"
#include "src/execution/pipe/pipex_bonus.h"
#include "src/execution/redirection/redirection_bonus.h"
#include <readline/readline.h>
#include <stdio.h>

pid_t	g_shell_state;

void	free_tokens_stack_ast(t_main_args **args)
{
	t_tokens	*tmp;
	t_stack		*tmp2;

	while ((*args)->tokens)
	{
		tmp = (*args)->tokens;
		(*args)->tokens = (*args)->tokens->next;
		free(tmp->cmd);
		free(tmp);
	}
	while ((*args)->stack)
	{
		tmp2 = (*args)->stack;
		(*args)->stack = (*args)->stack->next;
		free(tmp2);
	}
	free_ast((*args)->ast);
}

void	exec_ast(t_main_args **args, int *last_exit_status)
{
	bool	has_pipe;

	has_pipe = detect_pipe_in_ast((*args)->ast);
	prepare_all_heredocs((*args)->ast, (*args)->my_env, &(*args)->exit_status,
		has_pipe);
	(*args)->exit_status = execute_node_with_redirections((*args)->ast,
			&(*args)->my_env, has_pipe, last_exit_status);
}

void	main_help_fn(t_main_args *args, int *last_exit_status)
{
	args->tokens = tokens_list(args->args);
	free_args(args->args);
	args->stack = shuntin_yard(args->tokens);
	args->ast = make_tree(args->stack);
	if (args->ast)
		exec_ast(&args, last_exit_status);
	free_tokens_stack_ast(&args);
}

void	some_init_func(t_main_args *args, int argc, char **argv, char **env)
{
	args->exit_status = 0;
	args->my_env = get_env(env);
	(void)argc;
	(void)argv;
	setup_signals();
}

int	main(int argc, char **argv, char **env)
{
	t_main_args	args;
	static int	last_exit_status;

	some_init_func(&args, argc, argv, env);
	while (1)
	{
		set_interactive_mode();
		args.line = readline("ShellNote📜💀$ ");
		if (!args.line)
			break ;
		add_history(args.line);
		args.args = tokinize(args.line);
		free(args.line);
		args.line = NULL;
		if (!args.args)
			continue ;
		if (syntax_error(args.args))
		{
			last_exit_status = 258;
			free_args(args.args);
			continue ;
		}
		main_help_fn(&args, &last_exit_status);
	}
	return (free_env1(args.my_env), 0);
}
