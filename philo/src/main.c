/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/02/24 16:45:28 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tclDecls.h>
#include "philo.h"

void create_monitor_thread_and_start_simulation(pthread_t *monitor, t_philo *philosophers);

int	main(int argc, char **argv)
{
	t_philos_params		params;
	t_philo				*philos;
	int 				error;
	pthread_t 			monitor;

	error = 0;
	check_args(argc, argv, &error);
	set_philos_params_from_args(argv, &params, &error);
	create_all_philosophers(&philos, params, &error);
	init_all_philosophers(philos, params, &error);
	create_all_philosophers_threads(philos); //will create threads for all philos ! Philos will wait for the "start simulation mutex" to be unlocked
	create_monitor_thread_and_start_simulation(&monitor, philos);

//	clean_up(philos);
	return(error);
}

static void *monitor_routine(void *philos_casted_to_void);

void create_monitor_thread_and_start_simulation(pthread_t *monitor, t_philo *philosophers)
{
	pthread_create(monitor, NULL, &monitor_routine, philosophers);
}

//this will start the simulation by unlocking the "start simulation mutex"
static void *monitor_routine(void *philos_casted_to_void)
{
	const t_philo	*philos = (t_philo *)philos_casted_to_void;

	usleep(40);
//	while (true)
//		if (check_if_a_philo_died(philosophers_void))
//			return (NULL);
}
