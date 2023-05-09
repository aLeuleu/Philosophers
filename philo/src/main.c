/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:21:04 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void create_monitor_thread_and_start_simulation(pthread_t *monitor,\
t_philo *philosophers, int *error);

void	*philosopher_thread(void *philosopher_casted_to_void);

int	main(int argc, char **argv)
{
	t_philos_params	params;
	t_philo			*philos;
	int				error;
	pthread_t		monitor;

	pthread_mutex_init(&params.start_simulation_mutex, NULL);
	pthread_mutex_lock(&params.start_simulation_mutex);

	error = 0;
	check_args(argc, argv, &error);
	set_params_from_args(argv, &params, &error);
	init_all_philosophers(&philos, &params, &error);
	start_all_philosophers_threads(philos, &params, &error);
	create_monitor_thread_and_start_simulation(&monitor, philos, &error);
	//clean_up(philos);
	return (error);
}

static void create_monitor_thread_and_start_simulation(pthread_t *monitor, t_philo *philosophers, int *error)
{
	if (pthread_create(monitor, NULL, &monitor_routine, philosophers) != 0)
	{
		*error = THREAD_CREATION_ERROR;
		error_msg(*error);
		return ;
	}
	pthread_join(*monitor, NULL);
}
