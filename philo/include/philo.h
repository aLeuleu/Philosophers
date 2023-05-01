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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

#include "common_tools.h"

#define NUMBER_OF_PHILOSOPHERS ft_atoll(argv[1])

//common parameters for all philosophers
struct	s_params
{
	int 			nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	bool			a_philo_died;
	pthread_mutex_t	sync_start_mutex;
	pthread_mutex_t	print_mutex;
} typedef	t_params;

struct	s_philo
{
	int				id;
	pthread_t		pthread;
	int 			nb_meals_eaten;
	struct timeval	predicted_death_time;
	pthread_mutex_t	right_fork_mutex;
	pthread_mutex_t	*left_fork_mutex;
} typedef	t_philo;


void check_args(int argc, char **argv, int *error);
void set_global_params_from_args(char **argv, t_params *params, int *error);

#endif // PHILO_H
