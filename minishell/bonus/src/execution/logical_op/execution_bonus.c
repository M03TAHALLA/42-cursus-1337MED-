/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:35:53 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/02 20:48:15 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_bonus.h"

int	execute_logical_operator_with_redirections(t_ast_node *root, 
		char ***envp, bool has_pipe, int *last_exit_status)
{
	int	left_status;

	left_status = execute_node_with_redirections(root->left, 
			envp, has_pipe, last_exit_status);
	if (root->type == AST_AND)
	{
		if (left_status == 0)
			return (execute_node_with_redirections(root->right, 
					envp, has_pipe, last_exit_status));
		return (left_status);
	}
	if (root->type == AST_OR)
	{
		if (left_status != 0)
			return (execute_node_with_redirections(root->right, 
					envp, has_pipe, last_exit_status));
		return (0);
	}
	return (0);
}

int	execute_node_with_redirections(t_ast_node *node, 
		char ***envp, bool has_pipe, int *last_exit_status)
{
	bool		is_pipe;

	if (!node)
		return (0);
	is_pipe = has_pipe || (node->type == AST_PIPE);
	if (node->type == AST_CMD)
		return (execute_cmd_with_redirections(node, envp, 
				last_exit_status, is_pipe));
	if (node->type == AST_PIPE)
		return (execute_complex_pipeline(node, envp, 
				last_exit_status, true));
	if (node->type == AST_AND || node->type == AST_OR)
		return (execute_logical_operator_with_redirections(node, 
				envp, is_pipe, last_exit_status));
	close_redirections(node);
	return (*last_exit_status);
}
