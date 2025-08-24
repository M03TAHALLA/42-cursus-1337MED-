/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:48:17 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/25 11:06:10 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_bonus.h"

int	handle_output_redirection(char *file, int append_mode)
{
	char	*filetrimmed;
	int		flags;

	flags = O_WRONLY | O_CREAT;
	if (append_mode)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	filetrimmed = ft_strtrim(file, " ");
	if (!filetrimmed)
		return (0);
	if (open_and_dup_output(filetrimmed, flags) == -1)
	{
		free(filetrimmed);
		return (-1);
	}
	free(filetrimmed);
	return (0);
}

int	handle_heredoc_dup(int heredoc_fd)
{
	if (dup2(heredoc_fd, STDIN_FILENO) == -1)
	{
		perror("ShellNote");
		close(heredoc_fd);
		return (-1);
	}
	close(heredoc_fd);
	return (0);
}

void	handle_heredoc_child_redir(int *pipe_fd, char *delimiter, 
	char **envp, int *last_exit_status)
{
	close(pipe_fd[0]);
	read_heredoc_input(pipe_fd, delimiter, envp, last_exit_status);
	exit(0);
}

int	handle_heredoc_parent_re(int *pipe_fd)
{
	int	status;

	close(pipe_fd[1]);
	waitpid(-1, &status, 0);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("ShellNote");
		close(pipe_fd[0]);
		return (-1);
	}
	close(pipe_fd[0]);
	return (0);
}

int	handle_heredoc(char *delimiter, int heredoc_fd, char **envp, 
	int *last_exit_status)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (!delimiter || delimiter[0] == '\0')
		return (handle_redirection_error(
				"ShellNote: syntax error near unexpected token `newline'\n"));
	if (heredoc_fd >= 0)
		return (handle_heredoc_dup(heredoc_fd));
	if (pipe(pipe_fd) == -1)
	{
		perror("ShellNote");
		return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("ShellNote: fork");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (-1);
	}
	if (pid == 0)
		handle_heredoc_child_redir(pipe_fd, delimiter, envp, last_exit_status);
	return (handle_heredoc_parent_re(pipe_fd));
}
