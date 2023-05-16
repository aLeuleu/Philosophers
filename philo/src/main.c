/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:52:04 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static void	create_monitor_thread_and_start_simulation(pthread_t *monitor, \
														t_philo *philosophers, \
														int *error);
static void	clean_up(t_philo *philos);
static void	destroy_this_philo_fork(t_philo *philosopher);

void		*philosopher_thread(void *philosopher_casted_to_void);

int	main(int argc, char **argv)
{
	t_philos_params	params;
	t_philo			*philos;
	int				error;
	pthread_t		monitor;

	error = 0;
	check_args(argc, argv, &error);
	set_params_from_args(argv, &params, &error);
	init_all_philosophers(&philos, &params, &error);
	start_all_philosophers_threads(philos, &params, &error);
	create_monitor_thread_and_start_simulation(&monitor, philos, &error);
	clean_up(philos);
	return (error);
}

static void	create_monitor_thread_and_start_simulation(pthread_t *monitor,
		t_philo *philosophers, int *error)
{
	if (*error)
		return ;
	philosophers->params->start_time = get_current_time();
	pthread_mutex_unlock(&philosophers->params->simulation_start_mutex);
	pthread_create(monitor, NULL, &monitor_thread, philosophers);
	pthread_join(*monitor, NULL);
}

static void	clean_up(t_philo *philos)
{
	int	size;

	size = philos->params->nb_philos;
	while (size--)
		pthread_join(philos[size].pthread, NULL);
	size = philos->params->nb_philos;
	while (size--)
		destroy_this_philo_fork(philos + size);
	free(philos);
}

static void	destroy_this_philo_fork(t_philo *philosopher)
{
	pthread_mutex_destroy(&philosopher->right_fork_mutex);
}
