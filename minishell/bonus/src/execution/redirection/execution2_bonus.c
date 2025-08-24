/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:59:51 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/25 11:21:44 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_bonus.h"

static int	handle_heredoc_redirection(t_redirection *redir, 
	char **envp, int *last_exit_status)
{
	int	heredoc_fd;

	heredoc_fd = -1;
	if (redir->heredoc_fd >= 0)
		heredoc_fd = redir->heredoc_fd;
	if (handle_heredoc(redir->file, heredoc_fd, envp, last_exit_status) < 0)
		return (1);
	return (0);
}

static int	handle_input_redir(t_redirection *redir, 
	char **envp, int *last_exit_status)
{
	char	*file;

	file = expand_argument(redir->file, envp, last_exit_status, 0);
	if (!file)
		return (1);
	if (handle_input_redirection(file) < 0)
	{
		free(file);
		return (1);
	}
	free(file);
	return (0);
}

static int	handle_output_redir(t_redirection *redir, char **envp, 
	int *last_exit_status, int append_mode)
{
	char	*file;

	file = expand_argument(redir->file, envp, last_exit_status, 0);
	if (!file)
		return (1);
	if (handle_output_redirection(file, append_mode) < 0)
	{
		free(file);
		return (1);
	}
	free(file);
	return (0);
}

static int	handle_single_redirection(t_redirection *redir, 
	char **envp, int *last_exit_status)
{
	if (redir->type == TOKEN_REDIR_IN)
		return (handle_input_redir(redir, envp, last_exit_status));
	else if (redir->type == TOKEN_REDIR_OUT)
		return (handle_output_redir(redir, envp, last_exit_status, 0));
	else if (redir->type == TOKEN_APPEND)
		return (handle_output_redir(redir, envp, last_exit_status, 1));
	else if (redir->type == TOKEN_HEREDOC)
		return (handle_heredoc_redirection(redir, envp, last_exit_status));
	return (0);
}

int	handle_redirections(t_ast_node *node, char **envp, int *last_exit_status)
{
	t_redirection	*redir;

	redir = node->redirections;
	while (redir)
	{
		if (handle_single_redirection(redir, envp, last_exit_status))
			return (1);
		redir = redir->next;
	}
	return (0);
}
