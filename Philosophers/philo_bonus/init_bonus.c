/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:56:04 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/20 16:03:31 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	unlink_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_MEALS);
	sem_unlink(SEM_EXIT);
}

int	init_semaphores(t_data *data)
{
	unlink_semaphores();
	data->forks = sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0644, data->num_philos);
	if (data->forks == SEM_FAILED)
		return (ERROR);
	data->print_sem = sem_open(SEM_PRINT, O_CREAT | O_EXCL, 0644, 1);
	if (data->print_sem == SEM_FAILED)
		return (ERROR);
	data->death_sem = sem_open(SEM_DEATH, O_CREAT | O_EXCL, 0644, 1);
	if (data->death_sem == SEM_FAILED)
		return (ERROR);
	data->meals_sem = sem_open(SEM_MEALS, O_CREAT | O_EXCL, 0644, 1);
	if (data->meals_sem == SEM_FAILED)
		return (ERROR);
	data->meals_exit = sem_open(SEM_EXIT, O_CREAT | O_EXCL, 0644, 0);
	if (data->meals_exit == SEM_FAILED)
		return (ERROR);
	return (SUCCESS);
}

int	init_simulation(t_data *data)
{
	int	i;

	data->philos = NULL;
	data->pids = NULL;
	if (init_semaphores(data) == ERROR)
		return (ERROR);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (ERROR);
	data->pids = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pids)
		return (free(data->philos), ERROR);
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = get_time();
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		i++;
	}
	data->dead = 0;
	return (SUCCESS);
}
