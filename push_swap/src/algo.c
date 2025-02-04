/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:16:01 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/03 10:11:55 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max(t_node *stack)
{
	int	max;
	int	index;
	int	i;

	index = 0;
	i = 1;
	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

static void	push_to_b(t_node **stack_a, t_node **stack_b, int *begin, int *end)
{
	if ((*stack_a)->index > *end)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
	}
	else if ((*stack_a)->index < *begin)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		write(1, "pb\nrb\n", 6);
		(*begin)++;
		(*end)++;
	}
	else if ((*stack_a)->index >= *begin && (*stack_a)->index <= *end)
	{
		pb(stack_a, stack_b);
		write(1, "pb\n", 3);
		(*begin)++;
		(*end)++;
	}
}

static void	sort_stack_b_to_a(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b != NULL)
	{
		if (find_max(*stack_b) == 0)
		{
			pa(stack_a, stack_b);
			write(1, "pa\n", 3);
			continue ;
		}
		if (find_max(*stack_b) >= (stack_size(*stack_b) / 2))
		{
			rrb(stack_b);
			write(1, "rrb\n", 4);
		}
		else
		{
			rb(stack_b);
			write(1, "rb\n", 3);
		}
	}
}

void	algo_sort(t_node **stack_a, t_node **stack_b)
{
	int	range;
	int	begin;
	int	end;

	range = ft_range(stack_size(*stack_a));
	begin = 0;
	end = range;
	while (*stack_a)
	{
		push_to_b(stack_a, stack_b, &begin, &end);
	}
	sort_stack_b_to_a(stack_a, stack_b);
}

void	sorting(int count_args, t_node **stack_a, t_node **stack_b)
{
	if (count_args == 5)
		sort_five(stack_a, stack_b);
	else if (count_args == 3)
		sort_three(stack_a);
	else if (count_args == 4)
		sort_four(stack_a, stack_b);
	else
		algo_sort(stack_a, stack_b);
}
