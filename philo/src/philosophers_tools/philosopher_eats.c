/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:15:16 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:51:08 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo);
static int	take_fork(t_philo *philo, pthread_mutex_t *fork_mutex);
static void	update_time_to_death_and_time_to_eat(t_philo *philo,
				struct timeval *time_to_eat);
static void	release_both_forks(t_philo *philosopher);

int	philosopher_eats(t_philo *philo)
{
	struct timeval	time_to_eat;

	if (take_forks(philo))
		return (-1);
	update_time_to_death_and_time_to_eat(philo, &time_to_eat);
	if (print_state_change("%lli\t%i is eating\n", philo, philo->params) < 0)
	{
		release_both_forks(philo);
		return (-1);
	}
	if (philo->params->nb_of_meals_to_eat != INFINITE_EAT)
	{
		pthread_mutex_lock(&philo->nb_meals_eaten_mutex);
		philo->nb_meals_eaten++;
		pthread_mutex_unlock(&philo->nb_meals_eaten_mutex);
	}
	sleep_till(time_to_eat, philo);
	release_both_forks(philo);
	return (0);
}

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (take_fork(philo, &philo->right_fork_mutex) < 0)
			return (-1);
		if (take_fork(philo, philo->left_fork_mutex) < 0)
		{
			pthread_mutex_unlock(&philo->right_fork_mutex);
			return (-1);
		}
	}
	else
	{
		if (take_fork(philo, philo->left_fork_mutex) < 0)
			return (-1);
		if (take_fork(philo, &philo->right_fork_mutex) < 0)
		{
			pthread_mutex_unlock(philo->left_fork_mutex);
			return (-1);
		}
	}
	return (0);
}

static int	take_fork(t_philo *philo, pthread_mutex_t *fork_mutex)
{
	pthread_mutex_lock(fork_mutex);
	if (print_state_change("%lli\t%i has taken a fork \n", \
			philo, philo->params) < 0)
	{
		pthread_mutex_unlock(fork_mutex);
		return (-1);
	}

	return (0);
}

static void	update_time_to_death_and_time_to_eat(t_philo *philo,
				struct timeval *time_to_eat)
{
	const struct timeval	current_time = get_current_time();
	const t_philos_params	*params = philo->params;

	*time_to_eat = current_time;
	pthread_mutex_lock(&philo->predicted_death_time_mutex);
	philo->predicted_death_time = current_time;
	timeval_add_ms(&philo->predicted_death_time, params->time_to_die);
	pthread_mutex_unlock(&philo->predicted_death_time_mutex);
	timeval_add_ms(time_to_eat, params->time_to_eat);
}

static void	release_both_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(&philosopher->right_fork_mutex);
	pthread_mutex_unlock(philosopher->left_fork_mutex);
}
