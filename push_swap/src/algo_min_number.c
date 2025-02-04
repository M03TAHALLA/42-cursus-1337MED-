/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:07:11 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/31 12:56:12 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_smallest_node(t_node *stack)
{
	t_node	*current;
	t_node	*smallest;

	if (!stack)
		return (NULL);
	current = stack;
	smallest = stack;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

static void	r_to_small_node(t_node **stack_a, t_node *small_n, int small_i)
{
	int	size;

	size = stack_size(*stack_a);
	if (small_i <= size / 2)
	{
		while (*stack_a != small_n)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (*stack_a != small_n)
		{
			rra(stack_a);
			write(1, "rra\n", 4);
		}
	}
}

void	push_smallest_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_node;
	int		index;
	int		smallest_index;
	t_node	*current;

	if (!stack_a || !(*stack_a))
		return ;
	smallest_node = find_smallest_node(*stack_a);
	index = 0;
	smallest_index = 0;
	current = *stack_a;
	while (current)
	{
		if (current == smallest_node)
			smallest_index = index;
		current = current->next;
		index++;
	}
	r_to_small_node(stack_a, smallest_node, smallest_index);
	pb(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	sort_three_cases(stack_a, first, second, third);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		sa(stack_a);
		write(1, "sa\n", 3);
	}
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
}
