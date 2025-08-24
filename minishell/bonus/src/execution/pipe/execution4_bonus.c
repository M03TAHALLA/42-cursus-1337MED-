/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:36:38 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 11:39:13 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_state_changing_right_cmd(t_ast_node *node)
{
	return (node && node->type == AST_CMD && 
		node->args && node->args[0] && 
		is_builtin(node->args[0]) && 
		is_state_changing_builtin(node->args[0]));
}

int	handle_complex_right_pipe(t_ast_node *node, char ***envp, 
	int *last_exit_status)
{
	int	fd[2];
	int	pid_left;
	int	result;

	if (pipe(fd) < 0)
		return (perror("pipe"), 1);
	pid_left = prepare_left_child(fd, node->left, envp, last_exit_status);
	if (pid_left < 0)
		return (1);
	result = execute_complex_pipeline(node->right, envp, 
			last_exit_status, true);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_left, NULL, 0);
	return (result);
}

int	handle_builtin_execution(t_builtin_execution_data *exec_data)
{
	t_builtin_parent_data	data;

	data.fd = exec_data->fd;
	data.pidl = exec_data->pidl;
	data.right_cmd = exec_data->right_cmd;
	data.envp = exec_data->envp;
	data.last_exit_status = exec_data->last_exit_status;
	return (handle_builtin_parent(&data));
}
