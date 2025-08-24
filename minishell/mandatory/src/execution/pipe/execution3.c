/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:55:30 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/25 09:56:58 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_state_changing_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "unset") == 0);
}

void	cleanup_heredocs(t_pipeline_data *data)
{
	int				i;
	t_ast_node		*node;
	t_redirection	*redir;

	i = 0;
	while (i < data->num_cmds)
	{
		node = data->nodes[i];
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
		i++;
	}
}
