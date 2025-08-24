/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:49:45 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 12:51:10 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	handle_null_line(int pipe_fd[2], struct termios *old_term)
{
	write(STDOUT_FILENO, "\n", 1);
	close(pipe_fd[1]);
	tcsetattr(STDIN_FILENO, TCSANOW, old_term);
	return (0);
}

void	handle_line_expansion(int pipe_fd[2], char *line, 
		t_expansion_data *expansion_data)
{
	char	*expanded_line;

	if (expansion_data->should_expand)
	{
		expanded_line = expand_argument(line, expansion_data->envp, 
				expansion_data->last_exit_status, 0);
		write(pipe_fd[1], expanded_line, ft_strlen(expanded_line));
		free(expanded_line);
	}
	else
		write(pipe_fd[1], line, ft_strlen(line));
	write(pipe_fd[1], "\n", 1);
}
