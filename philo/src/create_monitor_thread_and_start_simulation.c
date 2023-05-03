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
	//set params->start_time= get_current_time();
//	while (true)
//		if (check_if_a_philo_died(philosophers_void))
//			return (NULL);
}