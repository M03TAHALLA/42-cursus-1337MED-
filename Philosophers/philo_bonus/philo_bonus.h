/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:54:35 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/19 21:21:57 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <signal.h>
# include <semaphore.h>

# define ERROR      -1
# define SUCCESS    0

# define SEM_FORKS  "/sem_forks"
# define SEM_PRINT  "/sem_print"
# define SEM_DEATH  "/sem_death"
# define SEM_MEALS  "/sem_meals"
# define SEM_EXIT   "/sem_exit"

typedef struct s_philo {
	int				id;
	pid_t			pid;
	long			last_meal;
	int				meals_eaten;
	pthread_t		monitor_thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_meals;
	long	start_time;
	sem_t	*forks;
	sem_t	*print_sem;
	sem_t	*death_sem;
	sem_t	*meals_sem;
	sem_t	*meals_exit;
	int		dead;
	t_philo	*philos;
	pid_t	*pids;
}	t_data;

int		parse_args(int argc, char **argv, t_data *data);
int		init_simulation(t_data *data);
void	start_simulation(t_data *data);
void	cleanup_simulation(t_data *data);
void	philo_routine(t_philo *philo);

long	get_time(void);
void	ft_usleep(int ms, t_data *data);
void	print_status(t_philo *philo, char *msg);
long	ft_atoi(const char *str);
int		get_death(t_data *data);
void	set_death(t_data *data);
void	*monitor_routine(void *arg);
void	*meals_monitor(void *arg);
void	unlink_semaphores(void);

#endif