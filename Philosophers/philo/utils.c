/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:28:31 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/20 16:00:29 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_death(t_data *data)
{
	int	flag;

	pthread_mutex_lock(&data->death_lock);
	flag = data->dead;
	pthread_mutex_unlock(&data->death_lock);
	return (flag);
}

void	set_death(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->dead = 1;
	pthread_mutex_unlock(&data->death_lock);
}

void	cleanup_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->death_lock);
	free(data->forks);
	free(data->philos);
}

void	ft_usleep(int ms, t_data *data)
{
	long	start_time;

	start_time = get_time();
	while (get_time() - start_time < ms)
	{
		if (get_death(data))
			break ;
		usleep(100);
	}
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (!get_death(philo->data))
	{
		printf("%ld %d %s\n", get_time() - philo->data->start_time,
			philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}
