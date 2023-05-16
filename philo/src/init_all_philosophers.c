/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_philosophers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:51:50 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_one_philo(t_philo *philo, int id, t_philos_params *params);
static void	set_all_left_forks(t_philo *philos, t_philos_params *params,
				int *error);
static void	create_right_fork_for_this_philo(t_philo *philo);

//for each philos :
// - set the id
// - set nb_meals_eaten to 0
// - create a right fork
// - set the left fork pointer to the previous philo's right fork
void	init_all_philosophers(t_philo **philos, t_philos_params *params, \
		int *error)
{
	int	i;

	create_all_philosophers(philos, params, error);
	if (*error)
		return ;
	i = -1;
	while (++i < params->nb_philos && !*error)
		init_one_philo(&(*philos)[i], i, params);
	set_all_left_forks(*philos, params, error);
}

static void	set_all_left_forks(t_philo *philos, t_philos_params *params,
		int *error)
{
	int	i;

	if (*error)
		return ;
	if (params->nb_philos == 1)
		return ;
	philos[0].left_fork_mutex = &philos[params->nb_philos].right_fork_mutex;
	i = 0;
	while (++i < params->nb_philos && !*error)
		philos[i].left_fork_mutex = &philos[i - 1].right_fork_mutex;
}

static void	init_one_philo(t_philo *philo, int id, t_philos_params *params)
{
	philo->id = id;
	philo->nb_meals_eaten = 0;
	philo->params = params;
	philo->has_started = false;
	create_right_fork_for_this_philo(philo);
}

static void	create_right_fork_for_this_philo(t_philo *philo)
{
	pthread_mutex_init(&philo->right_fork_mutex, NULL);
}
