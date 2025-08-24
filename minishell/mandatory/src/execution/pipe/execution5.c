/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:13:57 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 11:01:22 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_unused_pipes(t_pipeline_data *data, int num_cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds - 1)
	{
		close(data->pipes[i][0]);
		close(data->pipes[i][1]);
		i++;
	}
}

void	apply_state_changes(t_pipeline_data *data, 
	char ***envp, int *last_exit_status)
{
	int			i;
	t_ast_node	*node;

	i = 0;
	while (i < data->num_cmds)
	{
		if (data->state_changing_indexes[i])
		{
			node = data->nodes[i];
			if (is_builtin(node->args[0]) 
				&& is_state_changing_builtin(node->args[0]))
			{
				*last_exit_status = execute_builtin(
						node, envp, *last_exit_status, true);
			}
		}
		i++;
	}
}

pid_t	prepare_left_child(int *fd, t_ast_node *left_node, 
		char ***envp, int *last_exit_status)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exit(execute_node_with_redirections(left_node, envp, 
				true, last_exit_status));
	}
	return (pid);
}

int	handle_builtin_parent(t_builtin_parent_data *data)
{
	int	saved_stdin;
	int	status;
	int	exit_code;

	saved_stdin = dup(STDIN_FILENO);
	close(data->fd[1]);
	dup2(data->fd[0], STDIN_FILENO);
	waitpid(data->pidl, &status, 0);
	*(data->last_exit_status) = execute_builtin(
			data->right_cmd, data->envp, 
			*(data->last_exit_status), true);
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	close(data->fd[0]);
	exit_code = *(data->last_exit_status);
	return (exit_code);
}

pid_t	prepare_right_child(int *fd, t_ast_node *right_node, 
	char ***envp, int *last_exit_status)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		exit(execute_node_with_redirections(right_node, envp, 
				true, last_exit_status));
	}
	return (pid);
}
