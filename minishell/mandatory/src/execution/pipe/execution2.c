/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:12:14 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/02 20:56:08 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	handle_regular_pipeline(int *fd, pid_t pidl, pid_t pidr,
				int *last_exit_status)
{
	int	status;
	int	exit_code;

	close(fd[0]);
	close(fd[1]);
	waitpid(pidl, &status, 0);
	waitpid(pidr, &status, 0);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else
		exit_code = 1;
	*last_exit_status = exit_code;
	return (exit_code);
}

static int	handle_pipe_and_left_child(int *fd, t_ast_node *left_node, 
		char ***envp, int *last_exit_status)
{
	int	pidl;

	if (pipe(fd) < 0)
		return (perror("pipe"), 1);
	pidl = prepare_left_child(fd, left_node, envp, last_exit_status);
	if (pidl < 0)
		return (close(fd[0]), close(fd[1]), perror("fork"), -1);
	return (pidl);
}

int	execute_pipeline_with_redirections(t_ast_node *node, char ***envp, 
		int *last_exit_status)
{
	t_pipeline_data_redir	data;

	data.pidl = handle_pipe_and_left_child(data.fd, node->left, 
			envp, last_exit_status);
	if (data.pidl < 0)
		return (1);
	data.pidr = prepare_right_child(data.fd, node->right, 
			envp, last_exit_status);
	if (data.pidr < 0)
		return (close(data.fd[0]), kill(data.pidl, SIGKILL), 
			close(data.fd[1]), perror("fork"), 1);
	return (handle_regular_pipeline(data.fd, data.pidl, 
			data.pidr, last_exit_status));
}

int	execute_complex_pipeline(t_ast_node *node, char ***envp, 
	int *last_exit_status, bool has_pipe)
{
	if (node->type == AST_CMD)
		return (execute_cmd_with_redirections(node, envp, 
				last_exit_status, has_pipe));
	if (node->type != AST_PIPE)
		return (execute_node_with_redirections(node, 
				envp, has_pipe, last_exit_status));
	if (is_state_changing_right_cmd(node->right))
		return (execute_pipeline_with_redirections(node, envp, 
				last_exit_status));
	if (node->right && node->right->type == AST_PIPE)
		return (handle_complex_right_pipe(node, envp, last_exit_status));
	return (execute_pipeline_with_redirections(node, envp, 
			last_exit_status));
}
