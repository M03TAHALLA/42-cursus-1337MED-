/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:44:02 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/02 19:31:21 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
