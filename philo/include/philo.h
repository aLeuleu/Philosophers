/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:34:13 by alevra            #+#    #+#             */
/*   Updated: 2023/02/24 16:35:43 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PHILO_H)
#define PHILO_H
# define INVALID_ARGS -1
# define MALLOC_ERROR -2
# define MUTEX_INIT_ERROR -3
# define THREAD_CREATION_ERROR -4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

#include "common_tools.h"
#include "philo_time.h"

#define NUMBER_OF_PHILOSOPHERS ft_atoll(argv[1])

//common parameters for all philosophers
struct	s_philos_params
{
	int 			nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals_to_eat;
	bool			a_philo_died;
	struct timeval	start_time;
	pthread_mutex_t	a_philo_died_mutex;
	pthread_mutex_t	start_simulation_mutex;
	pthread_mutex_t	print_mutex;
} typedef	t_philos_params;

struct	s_philo
{
	int				id;
	pthread_t		pthread;
	int 			nb_meals_eaten;
	struct timeval	predicted_death_time;
	pthread_mutex_t	predicted_death_time_mutex;
	pthread_mutex_t	right_fork_mutex;
	pthread_mutex_t	*left_fork_mutex;
	t_philos_params *params;
} typedef	t_philo;

void check_args(int argc, char **argv, int *error);
void set_philos_params_from_args(char **argv, t_philos_params *params, int *error);
void create_all_philosophers(t_philo **philos, t_philos_params params, int *error);
void init_all_philosophers(t_philo *philos, t_philos_params *params, int *error);

#endif // PHILO_H
