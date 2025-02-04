/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:03 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/01 10:43:47 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	execute_move(char *move, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(move, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(move, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(move, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strncmp(move, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strncmp(move, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(move, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strncmp(move, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strncmp(move, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strncmp(move, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strncmp(move, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		print_error();
}

void	read_moves(t_node **stack_a, t_node **stack_b)
{
	char	*moves;

	moves = get_next_line(0);
	while (moves != NULL)
	{
		execute_move(moves, stack_a, stack_b);
		free(moves);
		moves = get_next_line(0);
	}
}
