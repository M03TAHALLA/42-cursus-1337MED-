/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:15:53 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/30 14:17:58 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	init_index(t_node *s)
{
	t_node	*temp1;
	t_node	*temp2;
	int		index;

	if (!s)
		return ;
	temp1 = s;
	while (temp1)
	{
		temp2 = s;
		index = 0;
		while (temp2)
		{
			if (temp1->value > temp2->value)
				index++;
			temp2 = temp2->next;
		}
		temp1->index = index;
		temp1 = temp1->next;
	}
}

void	check_node(void)
{
	write(2, "Error: Memory allocation failed\n", 33);
	exit(EXIT_FAILURE);
}

void	add_to_stack(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		check_node();
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	if (!*stack)
	{
		new_node->index = 0;
		*stack = new_node;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->previous = temp;
		new_node->index = 0;
	}
	init_index(*stack);
}
