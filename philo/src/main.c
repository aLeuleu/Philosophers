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

#include "philo.h"

void create_monitor_thread_and_start_simulation(pthread_t *monitor, t_philo *philosophers);

void create_and_start_all_philosophers_threads(t_philo *philos, t_philos_params params, int *error);

void *philosopher_routine(void *philosopher_casted_to_void);

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
	init_all_philosophers(philos, &params, &error);
	create_and_start_all_philosophers_threads(philos, params, &error);
	create_monitor_thread_and_start_simulation(&monitor, philos);

//	clean_up(philos);
	return(error);
}
