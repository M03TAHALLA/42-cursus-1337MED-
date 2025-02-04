/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:33:41 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/03 14:08:05 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_valid_numbers(char *arg)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = arg;
	while (*ptr)
	{
		while (*ptr == ' ')
			ptr++;
		if (*ptr == '+' || *ptr == '-')
			ptr++;
		if (ft_isdigit(*ptr))
		{
			count++;
			while (ft_isdigit(*ptr))
				ptr++;
		}
		else if (*ptr)
			ptr++;
	}
	return (count);
}

int	calculate_total_numbers(int argc, char **argv)
{
	int	total_count;
	int	i;

	total_count = 0;
	i = 1;
	while (i < argc)
	{
		total_count += count_valid_numbers(argv[i]);
		i++;
	}
	return (total_count);
}
