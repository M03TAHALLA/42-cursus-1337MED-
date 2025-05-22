/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:01:23 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/20 16:03:41 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms, t_data *data)
{
	long	start_time;

	(void)data;
	start_time = get_time();
	while (get_time() - start_time < ms)
		usleep(100);
}

void	print_status(t_philo *philo, char *msg)
{
	sem_wait(philo->data->print_sem);
	printf("%ld %d %s\n", get_time() - philo->data->start_time,
		philo->id, msg);
	sem_post(philo->data->print_sem);
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

void	cleanup_simulation(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_sem);
	sem_close(data->death_sem);
	sem_close(data->meals_sem);
	unlink_semaphores();
	free(data->philos);
	free(data->pids);
}
