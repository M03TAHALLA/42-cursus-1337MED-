/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:11:11 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:19 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../include/LIBFT/libft.h"
# include "src/get_next_line/get_next_line_bonus.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

int		check_parameter(int argc, char **argv);
void	is_empty_argument(const char *argv);
int		count_valid_numbers(char *arg);
int		calculate_total_numbers(int argc, char **argv);
void	check_result(int result);
int		is_valid_number(const char *str);
int		is_within_range(const char *str);
int		has_duplicate(int *arr, int size);
void	add_to_stack(t_node **stack, int value);
void	fill_stack_argc1(t_node **stack, int argc, char **argv);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	handle_n_args(int argc, char **argv, t_node **stack_a, int *count_arg);
int		chr_in(char *str, char c);
void	read_moves(t_node **stack_a, t_node **stack_b);
void	free_split(char **argument, int i);
void	free_stack(t_node **stack);
#endif