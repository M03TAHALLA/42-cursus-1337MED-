/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:23:10 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/20 16:00:59 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meal_limit(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->data->death_lock1);
	result = (philo->data->num_meals > 0 
			&& philo->meals_eaten >= philo->data->num_meals);
	pthread_mutex_unlock(&philo->data->death_lock1);
	return (result);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
	{
		handle_single_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 != 0)
	{
		print_status(philo, "is thinking");
		ft_usleep(philo->data->time_to_eat, philo->data);
	}
	while (!get_death(philo->data))
	{
		if (check_meal_limit(philo))
			return (NULL);
		take_forks(philo);
		eat(philo);
		philo_sleep_and_think(philo);
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_routine,
			&data->philos[i]);
		i++;
	}
}

void	join_threads(t_data *data, pthread_t monitor_thread)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}

void	start_simulation(t_data *data)
{
	pthread_t	monitor_thread;

	data->start_time = get_time();
	start_threads(data);
	pthread_create(&monitor_thread, NULL, (void *)check_death, data);
	join_threads(data, monitor_thread);
}
