/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:28:46 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/19 21:06:20 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_death(t_philo *philo, t_data *data)
{
	long	current_time;

	pthread_mutex_lock(&data->death_lock1);
	current_time = get_time();
	if (current_time - philo->last_meal >= data->time_to_die)
	{
		set_death(data);
		pthread_mutex_lock(&philo->data->print_lock);
		printf("%ld %d %s\n", get_time() - philo->data->start_time,
			philo->id + 1, "died");
		pthread_mutex_unlock(&philo->data->print_lock);
		pthread_mutex_unlock(&data->death_lock1);
		return (1);
	}
	pthread_mutex_unlock(&data->death_lock1);
	return (0);
}

int	check_finished_meals(t_data *data)
{
	int	i;
	int	all_finished;

	i = 0;
	all_finished = 1;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->death_lock1);
		if (data->num_meals > 0
			&& data->philos[i].meals_eaten < data->num_meals)
			all_finished = 0;
		pthread_mutex_unlock(&data->death_lock1);
		i++;
	}
	return (all_finished);
}

void	*check_death_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (check_philo_death(&data->philos[i], data))
			return (NULL);
		i++;
	}
	if (data->num_meals > 0 && check_finished_meals(data))
	{
		set_death(data);
		return (NULL);
	}
	return ((void *)1);
}

void	*check_death(t_data *data)
{
	while (1)
	{
		if (!check_death_loop(data))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
