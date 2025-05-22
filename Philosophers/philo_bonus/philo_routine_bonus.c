/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:57:14 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/20 16:03:14 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_status(philo, "has taken a fork");
	sem_wait(philo->data->forks);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
}

void	eat(t_philo *philo)
{
	sem_wait(philo->data->meals_sem);
	philo->last_meal = get_time();
	sem_post(philo->data->meals_sem);
	ft_usleep(philo->data->time_to_eat, philo->data);
	sem_wait(philo->data->meals_sem);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->data->num_meals)
		sem_post(philo->data->meals_exit);
	sem_post(philo->data->meals_sem);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	philo_sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
	print_status(philo, "is thinking");
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;
	long	current_time;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->meals_sem);
		current_time = get_time();
		if (current_time - philo->last_meal >= philo->data->time_to_die)
		{
			sem_post(philo->data->meals_sem);
			sem_wait(philo->data->print_sem);
			printf("%ld %d died\n", get_time() - philo->data->start_time,
				philo->id + 1);
			exit(1);
		}
		if (philo->data->num_meals > 0 
			&& philo->meals_eaten >= philo->data->num_meals)
			sem_post(philo->data->meals_sem);
		sem_post(philo->data->meals_sem);
		usleep(500);
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	if (philo->data->num_philos == 1)
	{
		sem_wait(philo->data->forks);
		print_status(philo, "has taken a fork");
		usleep(philo->data->time_to_die * 1000);
		print_status(philo, "died");
		exit(1);
	}
	pthread_create(&philo->monitor_thread, NULL, monitor_routine, philo);
	pthread_detach(philo->monitor_thread);
	if (philo->id % 2 != 0)
	{
		print_status(philo, "is thinking");
		ft_usleep(philo->data->time_to_eat / 2, philo->data);
	}
	while (1)
	{
		take_forks(philo);
		eat(philo);
		philo_sleep_and_think(philo);
	}
}
