/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_number_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:57:10 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/02 11:32:48 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	handle_second_case(t_node **stack_a)
{
	sa(stack_a);
	rra(stack_a);
	write(1, "sa\n", 3);
	write(1, "rra\n", 4);
}

static void	handle_fourth_case(t_node **stack_a)
{
	sa(stack_a);
	ra(stack_a);
	write(1, "sa\n", 3);
	write(1, "ra\n", 3);
}

void	sort_three_cases(t_node **stack_a, int first, int second, int third)
{
	if (first > second && second < third && first < third)
	{
		sa(stack_a);
		write(1, "sa\n", 3);
	}
	else if (first > second && second > third)
	{
		handle_second_case(stack_a);
	}
	else if (first > second && second < third && first > third)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
	}
	else if (first < second && second > third && first < third)
	{
		handle_fourth_case(stack_a);
	}
	else if (first < second && second > third && first > third)
	{
		rra(stack_a);
		write(1, "rra\n", 4);
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
}

int	ft_range(int stack_size)
{
	if (stack_size >= 6 && stack_size <= 50)
		return (11);
	else if (stack_size > 50 && stack_size <= 100)
		return (15);
	else if (stack_size > 100 && stack_size <= 200)
		return (19);
	else if (stack_size > 200 && stack_size <= 500)
		return (36);
	else if (stack_size > 500)
		return (50);
	return (0);
}
