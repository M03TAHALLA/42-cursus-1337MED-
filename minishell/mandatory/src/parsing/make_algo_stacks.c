/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_algo_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:13:27 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/12 11:01:08 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	push_op(t_stack **stack, t_tokens *token)
{
	t_stack	*new_node;

	if (!token)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->token = token;
	new_node->next = *stack;
	*stack = new_node;
}

void	handle_parnthesis(t_stack **op_stack, t_stack **output_queue,
		t_tokens *token)
{
	t_tokens	*tmp;

	if (token->type == TOKEN_PAREN_OPEN)
		push_op(op_stack, token);
	else if (token->type == TOKEN_PAREN_CLOSE)
	{
		while (*op_stack && (*op_stack)->token->type != TOKEN_PAREN_OPEN)
		{
			tmp = pop(op_stack);
			push(&(*output_queue), tmp);
		}
		if (*op_stack && (*op_stack)->token->type == TOKEN_PAREN_OPEN)
			pop(op_stack);
	}
}

void	init_sy_args(t_sy__args *sy_args)
{
	sy_args->output_queue = NULL;
	sy_args->op_stack = NULL;
	sy_args->tmp = NULL;
}

static void	handle_cases(t_sy__args *sy_args, t_tokens *tokens)
{
	if (tokens->type == TOKEN_COMMAND)
		push(&sy_args->output_queue, tokens);
	else if (tokens->type == TOKEN_PIPE || tokens->type == TOKEN_AND
		|| tokens->type == TOKEN_OR)
	{
		while (sy_args->op_stack && sy_args->op_stack->token->type 
			!= TOKEN_PAREN_OPEN && check_prio(sy_args->op_stack->token) 
			>= check_prio(tokens))
		{
			sy_args->tmp = pop(&sy_args->op_stack);
			push(&sy_args->output_queue, sy_args->tmp);
		}
		push_op(&sy_args->op_stack, tokens);
	}
	else if (tokens->type == TOKEN_PAREN_OPEN
		|| tokens->type == TOKEN_PAREN_CLOSE)
		handle_parnthesis(&sy_args->op_stack, &sy_args->output_queue, tokens);
}

t_stack	*shuntin_yard(t_tokens *tokens)
{
	t_sy__args	sy_args;

	init_sy_args(&sy_args);
	while (tokens)
	{
		handle_cases(&sy_args, tokens);
		tokens = tokens->next;
	}
	while (sy_args.op_stack)
	{
		sy_args.tmp = pop(&sy_args.op_stack);
		push(&sy_args.output_queue, sy_args.tmp);
	}
	return (sy_args.output_queue);
}
