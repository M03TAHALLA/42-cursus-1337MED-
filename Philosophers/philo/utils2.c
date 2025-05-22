/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:37:15 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/19 19:39:01 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
}

void	eat(t_philo *philo)
{
	update_meal_time(philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	increment_meals(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
	print_status(philo, "is thinking");
}

void	update_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_lock1);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->death_lock1);
}

void	increment_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_lock1);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_lock1);
}
