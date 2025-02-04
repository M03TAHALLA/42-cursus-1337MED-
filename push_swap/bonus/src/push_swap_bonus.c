/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:10:07 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/03 16:43:54 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_split(char **argument, int i)
{
	while (i > 0)
	{
		i--;
		free(argument[i]);
	}
	free(argument);
}

void	check_result(int result)
{
	if (result == 0)
	{
		write(2, "Error\nInvalid Arguments(Empty String)\n", 38);
		exit(1);
	}
	if (result == 5)
	{
		write(2, "Error\nNot Contain Only numbers\n", 31);
		exit(1);
	}
	if (result == 6)
	{
		write(2, "Error\nNumbers must be between INT_MAX and INT_MIN\n", 50);
		exit(1);
	}
	if (result == 8)
	{
		write(2, "Error\nDuplicate Numbers\n", 24);
		exit(1);
	}
}

int	chr_in(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	handle_argc_2(char **argv, t_node **stack_a, int *count_arg)
{
	char	**argument;
	int		i;

	if (chr_in(argv[1], ' '))
	{
		if (ft_strlen(argv[1]) == 1)
			check_result(0);
		is_empty_argument(argv[1]);
		argument = ft_split(argv[1], ' ');
		i = 0;
		while (argument[i])
			i++;
		fill_stack_argc1(stack_a, i, argument);
		*count_arg = i;
		free_split(argument, i);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		result;
	int		count_arg;

	stack_a = NULL;
	stack_b = NULL;
	count_arg = 0;
	if (argc < 2)
		exit(0);
	result = check_parameter(argc, argv);
	check_result(result);
	if (argc == 2)
		handle_argc_2(argv, &stack_a, &count_arg);
	else
		handle_n_args(argc, argv, &stack_a, &count_arg);
	read_moves(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
