/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:02:07 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/27 12:17:28 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_bonus.h"

static void	handle_heredoc_child(int pipe_fd[2], char *file, 
	char **envp, int *last_exit_status)
{
	close(pipe_fd[0]);
	read_heredoc_input(pipe_fd, file, envp, last_exit_status);
	exit(0);
}

static void	handle_heredoc_parent(int pipe_fd[2], pid_t pid, 
	t_redirection *redir)
{
	int	status;

	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	redir->heredoc_fd = pipe_fd[0];
}

static void	process_heredoc(t_redirection *redir, 
	char **envp, int *last_exit_status)
{
	int		heredoc_pipe[2];
	pid_t	pid;

	if (pipe(heredoc_pipe) == -1)
	{
		perror("ShellNote: pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("ShellNote: fork");
		close(heredoc_pipe[0]);
		close(heredoc_pipe[1]);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		handle_heredoc_child(heredoc_pipe, redir->file, envp, last_exit_status);
	else
		handle_heredoc_parent(heredoc_pipe, pid, redir);
}

void	prepare_heredocs(t_ast_node *node, char **envp, int *last_exit_status)
{
	t_redirection	*redir;

	redir = node->redirections;
	while (redir)
	{
		if (redir->type == TOKEN_HEREDOC)
			process_heredoc(redir, envp, last_exit_status);
		redir = redir->next;
	}
}

int	close_and_redirect(int pipe_fd[2])
{
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("ShellNote");
		close(pipe_fd[0]);
		return (-1);
	}
	close(pipe_fd[0]);
	return (0);
}
