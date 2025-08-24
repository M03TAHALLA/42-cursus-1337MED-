/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:24:57 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 12:28:30 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	handle_heredoc_error(char *message)
{
	write(2, message, ft_strlen(message));
	return (-1);
}

int	open_and_dup_output(char *filetrimmed, int flags)
{
	int	fd;

	fd = open(filetrimmed, flags, 0644);
	if (fd < 0 || dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("ShellNote");
		if (fd >= 0)
			close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	setup_terminal(struct termios *old_term)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, old_term);
	term = *old_term;
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	write(STDOUT_FILENO, "> ", 2);
	return (0);
}

void	write_line(t_buffer *buf)
{
	write(buf->pipe_fd[1], buf->line_buffer, buf->line_pos);
	write(buf->pipe_fd[1], "\n", 1);
	buf->line_pos = 0;
}

void	write_expanded_line(t_buffer *buf, char **envp, 
	int *last_exit_status)
{
	char	*expanded_line;

	buf->line_buffer[buf->line_pos] = '\0';
	expanded_line = expand_argument(buf->line_buffer, envp, 
			last_exit_status, 0);
	write(buf->pipe_fd[1], expanded_line, ft_strlen(expanded_line));
	write(buf->pipe_fd[1], "\n", 1);
	free(expanded_line);
	buf->line_pos = 0;
}
