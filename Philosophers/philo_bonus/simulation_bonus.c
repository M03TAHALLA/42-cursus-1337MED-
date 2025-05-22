/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:57:44 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/19 21:14:03 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*meals_monitor(void *arg)
{
	t_data	*data;
	int		i;
	int		status;
	int		exit_status;

	data = (t_data *)arg;
	i = 0;
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) != 0)
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status == 1)
		{
			while (i < data->num_philos)
			{
				sem_post(data->meals_exit);
				i++;
			}
			return (NULL);
		}
	}
	return (NULL);
}

void	*check_max_meals(void *arg)
{
	t_data	*data;
	int		status;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->num_philos)
	{
		sem_wait(data->meals_exit);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		kill(data->pids[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i++ < data->num_philos)
		waitpid(-1, &status, 0);
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	meals_thread;
	pthread_t	meals_exit;

	data->start_time = get_time();
	i = 0;
	while (i < data->num_philos)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
			philo_routine(&data->philos[i]);
		i++;
	}
	pthread_create(&meals_thread, NULL, meals_monitor, data);
	pthread_create(&meals_exit, NULL, check_max_meals, data);
	pthread_join(meals_exit, NULL);
	pthread_join(meals_thread, NULL);
}
