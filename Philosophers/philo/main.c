/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:28:09 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/20 15:18:17 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(t_data *data)
{
	if (data->num_philos <= 0 || data->time_to_die <= 0 || 
		data->time_to_eat <= 0 || data->time_to_sleep <= 0)
	{
		write(2, "All values must be positive integers.\n", 38);
		return (ERROR);
	}
	if (data->num_meals <= 0 && data->num_meals != -1)
	{
		write(2, "All values must be positive integers.\n", 38);
		return (ERROR);
	}
	return (SUCCESS);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid Input\n");
		return (ERROR);
	}
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = -1;
	return (validate_args(data));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_args(argc, argv, &data) == ERROR)
		return (EXIT_FAILURE);
	if (init_simulation(&data) == ERROR)
		return (EXIT_FAILURE);
	start_simulation(&data);
	cleanup_simulation(&data);
	return (EXIT_SUCCESS);
}
