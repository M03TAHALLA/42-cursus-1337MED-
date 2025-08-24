/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:56:34 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 17:40:28 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int	handle_redirections_and_builtin(t_ast_node *root, 
		t_exec_context *ctx)
{
	if (handle_redirections(root, *(ctx->envp), ctx->last_exit_status) == 0)
		*(ctx->last_exit_status) = execute_builtin(root, ctx->envp, 
				*(ctx->last_exit_status), ctx->has_pipe);
	else
		*(ctx->last_exit_status) = 1;
	restore_original_fds(ctx->original_fds);
	return (*(ctx->last_exit_status));
}

int	handle_builtin_redirections(t_ast_node *root, char ***envp, 
	int *last_exit_status, bool has_pipe)
{
	t_exec_context	ctx;

	ctx.envp = envp;
	ctx.last_exit_status = last_exit_status;
	ctx.has_pipe = has_pipe;
	save_original_fds(ctx.original_fds);
	return (handle_redirections_and_builtin(root, &ctx));
}

static int	handle_process_exit_status(int status, int *last_exit_status)
{
	if (WIFEXITED(status))
		*last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		*last_exit_status = 128 + WTERMSIG(status);
	else
		*last_exit_status = 1;
	return (*last_exit_status);
}

int	handle_non_builtin(t_ast_node *root, char **envp, 
		int *last_exit_status)
{
	int	status;
	int	id;

	id = process_with_redirections(root, envp, last_exit_status);
	waitpid(id, &status, 0);
	set_interactive_mode();
	return (handle_process_exit_status(status, last_exit_status));
}

int	execute_cmd_with_redirections(t_ast_node *root, char ***envp, 
	int *last_exit_status, bool has_pipe)
{
	if (is_builtin(root->args[0]))
		return (handle_builtin_redirections(root, envp, 
				last_exit_status, has_pipe));
	return (handle_non_builtin(root, *envp, last_exit_status));
}
