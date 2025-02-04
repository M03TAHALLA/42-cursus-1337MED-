/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:17:05 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/30 14:17:46 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_b;

	if (!stack_b || !(*stack_b))
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	top_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->previous = top_b;
	*stack_a = top_b;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_a;

	if (!stack_a || !(*stack_a))
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	top_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = top_a;
	*stack_b = top_a;
}
