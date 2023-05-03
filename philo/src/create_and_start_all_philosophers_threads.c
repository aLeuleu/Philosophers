/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_start_all_philosophers_threads.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/02/24 16:45:28 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_philosopher_routine(t_philo *philo, t_philos_params *params);
static void *philosopher_routine(void *philosopher_casted_to_void);

// Philos will wait for the "start simulation mutex" to be unlocked.
// If there is a thread creation failure,
// all threads that have already been created will be terminated.
void create_and_start_all_philosophers_threads(t_philo *philos, t_philos_params params, int *error)
{
	int	i;

	if (*error)
		return ;
	i = -1;
	while (++i < params.nb_philos)
	{
		if (pthread_create(&philos[i].pthread, NULL, &philosopher_routine,
						   &philos[i]) != 0)
		{
			*error = THREAD_CREATION_ERROR;
			error_msg(*error);
			break ;
		}
	}
	if (*error)
	//error handler here
}

static void *philosopher_routine(void *philosopher_casted_to_void)
{
	t_philo			*philo;
	t_philos_params	*params;

	philo = (t_philo *)philosopher_casted_to_void;
	params = philo->params;
	init_philosopher_routine(philo, params);

}

static int init_philosopher_routine(t_philo *philo, t_philos_params *params)
{
	struct timeval	tmp;

	pthread_mutex_lock(&params->start_simulation_mutex);
	pthread_mutex_unlock(&params->start_simulation_mutex);

	pthread_mutex_lock(&philo->predicted_death_time_mutex);
	philo->predicted_death_time = params->start_time;
	timeval_add_ms(&philo->predicted_death_time, params->time_to_die);
	pthread_mutex_unlock(&philo->predicted_death_time_mutex);
	//TODO if philo is even, make it think for a while
	if (philo->id % 2)
	{
		tmp = params->start_time;
		timeval_add_ms(&tmp, 10);
		if (print_state_change("%lli\t%i "PURPLE"is thinking\n"COLOR_RESET,
				philo) < 0)
		return (-1);
		sleep_till(tmp, philo);
		return (0);
	}
	return (0);
}