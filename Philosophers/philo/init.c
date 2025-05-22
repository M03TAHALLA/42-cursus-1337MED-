/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:28:21 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/20 15:59:57 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	usleep(philo->data->time_to_die * 1000);
	print_status(philo, "died");
	set_death(philo->data);
	pthread_mutex_unlock(philo->left_fork);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	if (*str == '\0')
		return (0);
	sign = 1;
	while (*str >= '0' && *str <= '9')
	{
		if (num > (LONG_MAX - (*str - '0')) / 10)
			return (-1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

int	init_simulation(t_data *data)
{
	int	i;

	i = -1;
	data->forks = NULL;
	data->philos = NULL;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (ERROR);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (free(data->forks), ERROR);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->death_lock1, NULL);
	while (++i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = get_time();
		data->philos[i].meals_eaten = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].data = data;
	}
	return (data->dead = 0, SUCCESS);
}
