/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:34:13 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:55:29 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define INVALID_ARGS -1
# define MALLOC_ERROR -2
# define MUTEX_INIT_ERROR -3
# define THREAD_CREATION_ERROR -4
# define INFINITE_EAT -1
# define NB_OF_USECONDS_IN_A_SECOND 1000000
# define NB_OF_USECONDS_IN_A_MILLISECOND 1000
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

//common parameters for all philosophers
typedef struct s_philos_params
{
	struct timeval	start_time;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals_to_eat;
	bool			a_philo_died;
	pthread_mutex_t	a_philo_died_mutex;
	pthread_mutex_t	simulation_start_mutex;
}					t_philos_params;

typedef struct s_philo
{
	int				id;
	pthread_t		pthread;
	bool			has_started;
	pthread_mutex_t	has_started_mutex;
	int				nb_meals_eaten;
	pthread_mutex_t	nb_meals_eaten_mutex;
	struct timeval	predicted_death_time;
	pthread_mutex_t	predicted_death_time_mutex;
	pthread_mutex_t	right_fork_mutex;
	pthread_mutex_t	*left_fork_mutex;
	t_philos_params	*params;
}	t_philo;

void			error_msg(int code);
long long		ft_atoll(const char *str);
bool			all_philos_are_alive(t_philos_params *params);
int				print_state_change(const char *format, t_philo *philosopher, \
				t_philos_params *params);
int				philosopher_eats(t_philo *philo);
int				philosopher_sleeps(t_philo *philo);
void			check_args(int argc, char **argv, int *error);
void			set_params_from_args(char **argv, \
t_philos_params *params, \
int *error);
void			init_all_philosophers(t_philo **philos, \
t_philos_params *params, \
int *error);
void			*monitor_thread(void *philos_casted_to_void);
void			start_all_philosophers_threads(t_philo *philos, \
t_philos_params *params, int *error);
void			create_all_philosophers(t_philo **philos, \
t_philos_params *params, int *error);
void			*philosopher_thread(void *philosopher_casted_to_void);
struct timeval	get_current_time(void);
long long		get_timestamp(const t_philo *philo, \
const struct timeval current_time);
void			timeval_add_ms(struct timeval *tv, const int n);
int				timeval_compare(const struct timeval t1,
					const struct timeval t2);
void			sleep_till(const struct timeval goal, const t_philo *philo);
#endif // PHILO_H
