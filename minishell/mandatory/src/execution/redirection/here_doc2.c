/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:23:10 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/25 11:34:55 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <signal.h>

static int	handle_end_of_input(int pipe_fd[2], 
	struct termios *old_term, char *line)
{
	free(line);
	close(pipe_fd[1]);
	tcsetattr(STDIN_FILENO, TCSANOW, old_term);
	return (0);
}

static int	handle_interactive_with_expansion(int pipe_fd[2], char *delimiter, 
		t_expansion_data *expansion_data)
{
	struct termios	old_term;
	char			*line;

	setup_terminal(&old_term);
	while (1)
	{
		rl_on_new_line();
		line = readline("");
		if (!line)
			return (handle_null_line(pipe_fd, &old_term));
		if (ft_strcmp(line, delimiter) == 0)
			return (handle_end_of_input(pipe_fd, &old_term, line));
		handle_line_expansion(pipe_fd, line, expansion_data);
		free(line);
		write(STDOUT_FILENO, "> ", 2);
	}
}

static int	check_delimiter_quotes(char *delimiter)
{
	size_t	len;

	len = ft_strlen(delimiter);
	if (len >= 2 && ((delimiter[0] == '\'' && delimiter[len - 1] == '\'') 
			|| (delimiter[0] == '"' && delimiter[len - 1] == '"')))
		return (1);
	return (0);
}

static char	*remove_quotes_delimiter(char *delimiter)
{
	size_t	len;

	len = ft_strlen(delimiter);
	if (len >= 2 && ((delimiter[0] == '\'' && delimiter[len - 1] == '\'') 
			|| (delimiter[0] == '"' && delimiter[len - 1] == '"')))
		return (ft_substr(delimiter, 1, len - 2));
	return (ft_strdup(delimiter));
}

int	read_heredoc_input(int pipe_fd[2], char *delimiter, 
	char **envp, int *last_exit_status)
{
	int					is_interactive;
	char				*clean_delimiter;
	t_expansion_data	expansion_data;
	int					result;

	signal(SIGINT, handle_hrdoc);
	is_interactive = isatty(STDIN_FILENO);
	expansion_data.envp = envp;
	expansion_data.last_exit_status = last_exit_status;
	expansion_data.should_expand = !check_delimiter_quotes(delimiter);
	clean_delimiter = remove_quotes_delimiter(delimiter);
	close(pipe_fd[0]);
	if (!is_interactive)
		result = handle_non_interactive_with_expansion(pipe_fd, 
				clean_delimiter, &expansion_data);
	else
		result = handle_interactive_with_expansion(pipe_fd, clean_delimiter, 
				&expansion_data);
	free(clean_delimiter);
	return (result);
}
