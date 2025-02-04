/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:17:20 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/30 14:17:20 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	process_number(char **ptr, int *arr, int *count)
{
	char	*start;
	char	temp;

	start = *ptr;
	while (**ptr && **ptr != ' ')
		(*ptr)++;
	temp = **ptr;
	**ptr = '\0';
	while (*start + 1 == '0')
		start++ ;
	if (!is_valid_number(start))
		return (5);
	if (!is_within_range(start))
		return (6);
	arr[(*count)++] = ft_atoi(start);
	**ptr = temp;
	if (**ptr)
		(*ptr)++;
	return (1);
}

int	process_argument(char *arg, int *arr, int *count)
{
	char	*ptr;
	int		result;

	ptr = arg;
	while (*ptr)
	{
		if (*ptr == ' ')
			ptr++;
		else
		{
			result = process_number(&ptr, arr, count);
			if (result != 1)
				return (result);
		}
	}
	return (1);
}

int	check_parameter(int argc, char **argv)
{
	int		count;
	int		i;
	int		*arr;
	char	*arg;
	int		result;

	count = 0;
	i = 1;
	arr = malloc(sizeof(int) * (calculate_total_numbers(argc, argv) + 1));
	if (!arr)
		return (0);
	while (i < argc)
	{
		arg = argv[i];
		if (arg[0] == '\0')
			return (free(arr), 0);
		result = process_argument(arg, arr, &count);
		if (result != 1)
			return (free(arr), result);
		i++;
	}
	if (has_duplicate(arr, count))
		return (free(arr), 8);
	return (free(arr), 1);
}

void	handle_argument(char *arg, t_node **stack_a, int *count_arg)
{
	char	**argument;
	int		j;
	int		i;

	j = 0;
	if (chr_in(arg, ' '))
	{
		if (ft_strlen(arg) == 1)
			check_result(0);
		i = 0;
		is_empty_argument(arg);
		argument = ft_split(arg, ' ');
		while (argument[j])
		{
			j++;
			(*count_arg)++;
		}
		fill_stack_argc1(stack_a, j, argument);
		free_split(argument, j);
	}
	else
	{
		add_to_stack(stack_a, ft_atoi(arg));
		(*count_arg)++;
	}
}

void	handle_n_args(int argc, char **argv, t_node **stack_a, int *count_arg)
{
	int		i;

	i = 1;
	while (i < argc)
		handle_argument(argv[i++], stack_a, count_arg);
}
