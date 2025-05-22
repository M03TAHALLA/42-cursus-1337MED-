/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:27:44 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/19 21:20:47 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

# define ERROR -1
# define SUCCESS 0

typedef struct s_philo {
	int				id;
	pthread_t		thread;
	long			last_meal;
	int				meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	death_lock1;
	int				dead;
	t_philo			*philos;
}	t_data;

int		parse_args(int argc, char **argv, t_data *data);
int		init_simulation(t_data *data);
void	start_simulation(t_data *data);
void	cleanup_simulation(t_data *data);
long	get_time(void);
void	ft_usleep(int ms, t_data *data);
void	print_status(t_philo *philo, char *msg);
void	*check_death(t_data *data);
long	ft_atoi(const char *str);
int		get_death(t_data *data);
void	set_death(t_data *data);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	philo_sleep_and_think(t_philo *philo);
void	update_meal_time(t_philo *philo);
void	increment_meals(t_philo *philo);
void	handle_single_philo(t_philo *philo);

#endif