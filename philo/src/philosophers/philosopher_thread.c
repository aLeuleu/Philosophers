/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:15:08 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:50:18 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philosopher_thread(t_philo *philo, t_philos_params *params);

void	*philosopher_thread(void *philosopher_casted_to_void)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher_casted_to_void;
	init_philosopher_thread(philo, philo->params);
	while (true)
	{
		if (philosopher_eats(philo) < 0)
			return (NULL);
		if (philosopher_sleeps(philo) < 0)
			return (NULL);
		if (print_state_change("%lli\t%i is thinking\n", philo, \
				philo->params) < 0)
			break ;
		usleep(100);
	}
	return (NULL);
}

static void	init_philosopher_thread(t_philo *philo, t_philos_params *params)
{
	struct timeval	tmp;

	pthread_mutex_lock(&philo->params->simulation_start_mutex);
	pthread_mutex_unlock(&philo->params->simulation_start_mutex);
	pthread_mutex_lock(&philo->predicted_death_time_mutex);
	philo->predicted_death_time = params->start_time;
	timeval_add_ms(&philo->predicted_death_time, params->time_to_die);
	pthread_mutex_unlock(&philo->predicted_death_time_mutex);
	pthread_mutex_lock(&philo->has_started_mutex);
	philo->has_started = true;
	pthread_mutex_unlock(&philo->has_started_mutex);
	if (philo->id % 2)
	{
		tmp = params->start_time;
		timeval_add_ms(&tmp, 50);
		if (print_state_change("%lli\t%i is thinking\n", philo, params) < 0)
			return ;
		sleep_till(tmp, philo);
		return ;
	}
}
