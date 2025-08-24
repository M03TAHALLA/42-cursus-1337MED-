/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:33:27 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/25 11:35:59 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_bonus.h"

int	check_delimiter(t_buffer *buf)
{
	buf->line_buffer[buf->line_pos] = '\0';
	if (ft_strcmp(buf->line_buffer, buf->delimiter) == 0)
	{
		close(buf->pipe_fd[1]);
		return (1);
	}
	return (0);
}

void	process_input_buffer(t_buffer *buf, char *buffer, int bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			if (check_delimiter(buf))
				return ;
			write_line(buf);
		}
		else if (buf->line_pos < 4095)
		{
			buf->line_buffer[buf->line_pos] = buffer[i];
			(buf->line_pos)++;
		}
		i++;
	}
}

void	process_input_buffer_with_expansion(t_buffer *buf, char *buffer, 
			int bytes_read, t_expansion_data *expansion_data)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			if (check_delimiter(buf))
				return ;
			write_expanded_line(buf, expansion_data->envp, 
				expansion_data->last_exit_status);
		}
		else if (buf->line_pos < 4095)
		{
			buf->line_buffer[buf->line_pos] = buffer[i];
			(buf->line_pos)++;
		}
		i++;
	}
}

static void	handle_remaining_line(t_buffer *buf, char **envp, 
	int *last_exit_status, int should_expand)
{
	if (buf->line_pos > 0 && !check_delimiter(buf))
	{
		if (should_expand)
			write_expanded_line(buf, envp, last_exit_status);
		else
			write_line(buf);
	}
}

int	handle_non_interactive_with_expansion(int pipe_fd[2], char *delimiter, 
		t_expansion_data *expansion_data)
{
	t_buffer	buf;
	char		buffer[4096];
	ssize_t		bytes_read;

	buf.line_pos = 0;
	buf.pipe_fd[0] = pipe_fd[0];
	buf.pipe_fd[1] = pipe_fd[1];
	buf.delimiter = delimiter;
	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (expansion_data->should_expand)
			process_input_buffer_with_expansion(&buf, buffer, bytes_read, 
				expansion_data);
		else
			process_input_buffer(&buf, buffer, bytes_read);
		if (check_delimiter(&buf))
			return (0);
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	}
	handle_remaining_line(&buf, expansion_data->envp, 
		expansion_data->last_exit_status, expansion_data->should_expand);
	close(pipe_fd[1]);
	return (0);
}
