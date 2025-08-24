/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:38:39 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/22 21:40:42 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "src/execution/pipe/pipex.h"

void	prepare_all_heredocs(t_ast_node *root, char **envp,
		int *last_exit_status, bool has_pipe)
{
	bool	current_has_pipe;

	if (!root)
		return ;
	current_has_pipe = has_pipe || (root->type == AST_PIPE);
	if (root->type == AST_CMD)
		prepare_heredocs(root, envp, last_exit_status);
	else if (root->type == AST_PIPE || root->type == AST_AND
		|| root->type == AST_OR)
	{
		prepare_all_heredocs(root->left, envp, last_exit_status,
			current_has_pipe);
		prepare_all_heredocs(root->right, envp, last_exit_status,
			current_has_pipe);
	}
}

bool	detect_pipe_in_ast(t_ast_node *node)
{
	if (!node)
		return (false);
	if (node->type == AST_PIPE && !(node->type == AST_AND)
		&& !(node->type == AST_OR))
		return (true);
	return (detect_pipe_in_ast(node->left) || detect_pipe_in_ast(node->right));
}

void	close_redirections(t_ast_node *node)
{
	t_redirection	*redir;

	if (!node)
		return ;
	redir = node->redirections;
	while (redir)
	{
		if (redir->type == TOKEN_HEREDOC && redir->heredoc_fd >= 0)
		{
			close(redir->heredoc_fd);
			redir->heredoc_fd = -1;
		}
		redir = redir->next;
	}
}

void	free_redirections(t_redirection *redir)
{
	t_redirection	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		if (tmp->file)
			free(tmp->file);
		free(tmp);
	}
}

void	free_ast(t_ast_node *node)
{
	t_redirection	*current;
	int				i;

	if (!node)
		return ;
	free_ast(node->left);
	free_ast(node->right);
	current = node->redirections;
	close_redirections(node);
	free_redirections(current);
	if (node->cmd)
		free(node->cmd);
	if (node->args)
	{
		i = 0;
		while (node->args[i])
			free(node->args[i++]);
		free(node->args);
	}
	free(node);
}
