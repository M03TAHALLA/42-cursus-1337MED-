/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_algo_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:03:31 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/12 11:01:16 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	push(t_stack **stack, t_tokens *token)
{
	t_stack	*new_node;
	t_stack	*current;

	if (!token)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->token = token;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

t_tokens	*pop(t_stack **stack)
{
	t_stack		*temp;
	t_tokens	*token;

	if (!*stack)
		return (NULL);
	temp = *stack;
	token = temp->token;
	*stack = temp->next;
	free(temp);
	return (token);
}

int	check_prio(t_tokens *token)
{
	if (token->type == TOKEN_PIPE)
		return (2);
	else if (token->type == TOKEN_AND || token->type == TOKEN_OR)
		return (1);
	return (0);
}
