/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:16:15 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/12 10:48:18 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	add_node_to_list(t_tokens **head, t_tokens **current,
		t_tokens **new_node)
{
	if (!*new_node)
		return ;
	if (!*head)
	{
		*head = *new_node;
		*current = *head;
	}
	else
	{
		(*current)->next = *new_node;
		*current = (*current)->next;
	}
	*new_node = NULL;
}

static void	create_special_tok_node(char **args, t_tokens **current,
		t_tokens **new_node, t_tokens **head)
{
	int	i;

	i = 0;
	add_node_to_list(head, current, new_node);
	if (!ft_strcmp(args[i], "|"))
		*new_node = ft_new_node(args[i], TOKEN_PIPE);
	else if (!ft_strcmp(args[i], "||"))
		*new_node = ft_new_node(args[i], TOKEN_OR);
	else if (!ft_strcmp(args[i], "&&"))
		*new_node = ft_new_node(args[i], TOKEN_AND);
	else if (!ft_strcmp(args[i], "("))
		*new_node = ft_new_node(args[i], TOKEN_PAREN_OPEN);
	else if (!ft_strcmp(args[i], ")"))
		*new_node = ft_new_node(args[i], TOKEN_PAREN_CLOSE);
	add_node_to_list(head, current, new_node);
}

static void	init_token_args(t_token_args *token_args)
{
	token_args->head = NULL;
	token_args->current = NULL;
	token_args->new_node = NULL;
	token_args->i = 0;
}

void	handle_conditions(char **args, t_token_args *t_a)
{
	if (args[t_a->i] && ft_is_red(args[t_a->i]))
	{
		if (!t_a->new_node)
			t_a->new_node = ft_new_node(ft_strdup(""), TOKEN_COMMAND);
		handle_red(&args[t_a->i], &t_a->new_node);
		if (!args[t_a->i + 1])
			t_a->i++;
		else
			t_a->i += 2;
	}
	else if (args[t_a->i] && (ft_is_cmd(args[t_a->i]) || args[t_a->i][0] == '\''
		|| args[t_a->i][0] == '\"'))
		t_a->i += build_cmd_str(&args[t_a->i], &t_a->new_node);
	else if (args[t_a->i])
		create_special_tok_node(&args[t_a->i++], &t_a->current, &t_a->new_node,
			&t_a->head);
	else
		t_a->i++;
}

t_tokens	*tokens_list(char **args)
{
	t_token_args	t_a;

	init_token_args(&t_a);
	if (!args)
		return (NULL);
	while (args[t_a.i])
	{
		handle_conditions(args, &t_a);
		if (!args[t_a.i] && t_a.new_node)
			add_node_to_list(&t_a.head, &t_a.current, &t_a.new_node);
	}
	return (t_a.head);
}
