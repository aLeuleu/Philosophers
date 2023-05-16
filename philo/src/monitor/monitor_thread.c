/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:15:08 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:50:00 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_if_a_philo_died(t_philo *philo);
static void	stop_philosophers(t_philos_params *params);
static bool	is_philosopher_dead(t_philo *philo);
static void	check_if_philo_has_eat_all_meals(int *philo_has_finished, \
int i, t_philo *philo);

//this will start the simulation by unlocking the "start simulation mutex"
void	*monitor_thread(void *philos_casted_to_void)
{
	t_philo	*philos;

	philos = (t_philo *)philos_casted_to_void;
	while (true)
		if (check_if_a_philo_died(philos))
			return (NULL);
}

static bool	check_if_a_philo_died(t_philo *philo)
{
	int				i;
	int				philo_has_finished;

	philo_has_finished = 0;
	i = philo->params->nb_philos;
	while (i--)
	{
		if (is_philosopher_dead(philo + i))
		{
			stop_philosophers(philo->params);
			printf("%lli\t%i died\n", \
					get_timestamp(philo, get_current_time()), \
				philo[i].id + 1);
			return (true);
		}
		check_if_philo_has_eat_all_meals(&philo_has_finished, i, philo);
	}
	if (philo_has_finished == philo->params->nb_philos)
		return (stop_philosophers(philo->params), true);
	return (usleep(1000), false);
}

static void	check_if_philo_has_eat_all_meals(int *philo_has_finished, \
int i, t_philo *philo)
{
	if (philo->params->nb_of_meals_to_eat != INFINITE_EAT)
	{
		pthread_mutex_lock(&philo[i].nb_meals_eaten_mutex);
		*philo_has_finished += philo[i].nb_meals_eaten >= \
		philo->params->nb_of_meals_to_eat;
		pthread_mutex_unlock(&philo[i].nb_meals_eaten_mutex);
	}
}

static bool	is_philosopher_dead(t_philo *philo)
{
	const struct timeval	current_time = get_current_time();
	bool					return_value;

	pthread_mutex_lock(&philo->has_started_mutex);
	if (!philo->has_started)
		return (pthread_mutex_unlock(&philo->has_started_mutex), false);
	pthread_mutex_unlock(&philo->has_started_mutex);
	pthread_mutex_lock(&philo->predicted_death_time_mutex);
	return_value = \
			timeval_compare(philo->predicted_death_time, current_time) <= 0;
	pthread_mutex_unlock(&philo->predicted_death_time_mutex);
	return (return_value);
}

static void	stop_philosophers(t_philos_params *params)
{
	pthread_mutex_lock(&params->a_philo_died_mutex);
	params->a_philo_died = true;
	pthread_mutex_unlock(&params->a_philo_died_mutex);
}
