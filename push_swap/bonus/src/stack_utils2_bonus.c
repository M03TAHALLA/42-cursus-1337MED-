/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:15:45 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/03 09:41:25 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	fill_stack_argc1(t_node **stack, int argc, char **argv)
{
	int	i;
	int	value;

	i = 0;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_to_stack(stack, value);
		i++;
	}
}

int	is_sorted(t_node *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
