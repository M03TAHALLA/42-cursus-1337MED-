/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:41:23 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/12 10:47:41 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_tokens	*ft_new_node(char *arg, int type)
{
	t_tokens	*node;

	node = malloc(sizeof(t_tokens));
	if (!node)
		return (NULL);
	node->cmd = ft_strdup(arg);
	if (!node->cmd)
	{
		free(node);
		return (NULL);
	}
	node->type = type;
	node->next = NULL;
	node->redirections = NULL;
	return (node);
}

void	put_redir(t_tokens *token, char *file, t_token_type type)
{
	t_redirection	*redir;
	t_redirection	*tmp;

	redir = malloc(sizeof(t_redirection));
	if (!redir)
		return ;
	redir->file = ft_strdup(file);
	if (!redir->file)
	{
		free(redir);
		return ;
	}
	redir->type = type;
	redir->next = NULL;
	if (!token->redirections)
		token->redirections = redir;
	else
	{
		tmp = token->redirections;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = redir;
	}
}

void	handle_red(char **args, t_tokens **new_node)
{
	int	i;

	i = 0;
	if (!ft_strcmp(args[i], "<"))
	{
		if (args[i + 1])
			put_redir(*new_node, args[i + 1], TOKEN_REDIR_IN);
	}
	else if (!ft_strcmp(args[i], ">"))
	{
		if (args[i + 1])
			put_redir(*new_node, args[i + 1], TOKEN_REDIR_OUT);
	}
	else if (!ft_strcmp(args[i], "<<"))
	{
		if (args[i + 1])
			put_redir(*new_node, args[i + 1], TOKEN_HEREDOC);
	}
	else if (!ft_strcmp(args[i], ">>"))
	{
		if (args[i + 1])
			put_redir(*new_node, args[i + 1], TOKEN_APPEND);
	}
}

int	check_null(t_tokens **new_node)
{
	if (!*new_node)
	{
		*new_node = ft_new_node("", TOKEN_COMMAND);
		if (!*new_node)
			return (0);
	}
	return (1);
}

int	build_cmd_str(char **args, t_tokens **new_node)
{
	char	*cmd_str;
	char	*temp;
	int		i;

	cmd_str = NULL;
	if (!check_null(new_node))
		return (0);
	i = 0;
	while (args[i] && ft_is_cmd(args[i]))
	{
		temp = (*new_node)->cmd;
		if (ft_strlen((*new_node)->cmd) > 0)
			(*new_node)->cmd = ft_strjoin(temp, " ");
		else
			(*new_node)->cmd = ft_strdup("");
		free(temp);
		if (!(*new_node)->cmd)
			return (i);
		temp = (*new_node)->cmd;
		(*new_node)->cmd = ft_strjoin(temp, args[i++]);
		free(temp);
		if (!(*new_node)->cmd)
			return (i - 1);
	}
	return (i);
}
