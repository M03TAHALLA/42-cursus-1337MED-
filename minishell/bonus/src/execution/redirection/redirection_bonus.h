/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:19:49 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/26 11:21:01 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_BONUS_H
# define REDIRECTION_BONUS_H

# include "../../../minishell_bonus.h"
# include <termios.h>
# include "../built_in/builtin_bonus.h"

typedef struct s_buffer
{
	char	line_buffer[4096];
	int		line_pos;
	int		pipe_fd[2];
	char	*delimiter;
}	t_buffer;

typedef struct s_expansion_data
{
	char	**envp;
	int		*last_exit_status;
	int		should_expand;
}	t_expansion_data;

int		handle_redirections(t_ast_node *node, char **envp, 
			int *last_exit_status);
int		read_heredoc_input(int pipe_fd[2], char *delimiter, 
			char **envp, int *last_exit_status);
int		close_and_redirect(int pipe_fd[2]);
int		setup_heredoc_pipe(int pipe_fd[2]);
void	prepare_heredocs(t_ast_node *node, char **envp, int *last_exit_status);
int		handle_heredoc_error(char *message);
int		handle_heredoc(char *delimiter, int heredoc_fd, 
			char **envp, int *last_exit_status);
int		handle_input_redirection(char *file);
int		handle_output_redirection(char *file, int append_mode);
void	process_input_buffer(t_buffer *buf, char *buffer, int bytes_read);
void	write_line(t_buffer *buf);
void	process_input_buffer_with_expansion(t_buffer *buf, char *buffer, 
			int bytes_read, t_expansion_data *expansion_data);
int		handle_non_interactive_with_expansion(int pipe_fd[2], 
			char *delimiter, t_expansion_data *expansion_data);
int		handle_redirection_error(char *message);
int		handle_heredoc_dup(int heredoc_fd);
int		open_and_dup_output(char *filetrimmed, int flags);
int		setup_terminal(struct termios *old_term);
void	write_expanded_line(t_buffer *buf, char **envp, int *last_exit_status);
void	handle_line_expansion(int pipe_fd[2], 
			char *line, t_expansion_data *expansion_data);
int		handle_null_line(int pipe_fd[2], struct termios *old_term);

#endif