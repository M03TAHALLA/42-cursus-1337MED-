/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:13:50 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 19:07:57 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_bonus.h"

void	handle_child_process(t_ast_node *node, char **env, 
	int *last_exit_status)
{
	char	*cmd;

	restore_default_signals();
	if (handle_redirections(node, env, last_exit_status) != 0)
		exit(EXIT_FAILURE);
	if ((!node->args[0] || node->args[0][0] == '\0') && node->redirections &&
		node->redirections->type == TOKEN_HEREDOC)
		exit(EXIT_SUCCESS);
	if (!node->args[0] || node->args[0][0] == '\0')
		exit(EXIT_SUCCESS);
	cmd = join_args(node->args);
	if (!cmd)
		exit(EXIT_FAILURE);
	execute_command(cmd, env, last_exit_status);
	free(cmd);
	exit(EXIT_FAILURE);
}

char	*allocate_result(const char *pattern)
{
	char	*result;

	result = malloc(ft_strlen(pattern) + 1);
	if (!result)
		return (NULL);
	return (result);
}

void	handle_quote(int *in_quotes, char *quote_char, char c, int *i)
{
	if (*in_quotes)
		*in_quotes = 0;
	else
	{
		*in_quotes = 1;
		*quote_char = c;
	}
	(*i)++;
}

void	save_original_fds(int original_fds[3])
{
	original_fds[0] = dup(STDIN_FILENO);
	original_fds[1] = dup(STDOUT_FILENO);
	original_fds[2] = dup(STDERR_FILENO);
}

void	restore_original_fds(int original_fds[3])
{
	dup2(original_fds[0], STDIN_FILENO);
	dup2(original_fds[1], STDOUT_FILENO);
	dup2(original_fds[2], STDERR_FILENO);
	close(original_fds[0]);
	close(original_fds[1]);
	close(original_fds[2]);
}
