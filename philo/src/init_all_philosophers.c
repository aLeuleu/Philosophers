/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_philosophers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:21:00 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_one_philo(t_philo *philo, int id, t_philos_params *params,
				int *error);
static void	set_all_left_forks(t_philo *philos, t_philos_params *params,
				int *error);
static void	create_right_fork_for_this_philo(t_philo *philo, int *error);

//for each philos :
// - set the id
// - set nb_meals_eaten to 0
// - create a right fork
// - set the left fork pointer to the previous philo's right fork
void	init_all_philosophers(t_philo *philos, t_philos_params *params,
		int *error)
{
	int	i;

	if (*error)
		return ;
	i = -1;
	while (++i < params->nb_philos && !*error)
		init_one_philo(&philos[i], i, params, error);
	set_all_left_forks(philos, params, error);
}

static void	set_all_left_forks(t_philo *philos, t_philos_params *params,
		int *error)
{
	int	i;

	if (*error)
		return ;
	philos[0].left_fork_mutex = &philos[params->nb_philos].right_fork_mutex;
	i = 0;
	while (++i < params->nb_philos && !*error)
		philos[i].left_fork_mutex = &philos[i - 1].right_fork_mutex;
}

static void	init_one_philo(t_philo *philo, int id, t_philos_params *params,
		int *error)
{
	philo->id = id;
	philo->nb_meals_eaten = 0;
	philo->params = params;
	create_right_fork_for_this_philo(philo, error);
}

static void	create_right_fork_for_this_philo(t_philo *philo, int *error)
{
	*error = pthread_mutex_init(&philo->right_fork_mutex, NULL);
	if (*error)
	{
		*error = MUTEX_INIT_ERROR;
		return (error_msg(*error));
	}
}
