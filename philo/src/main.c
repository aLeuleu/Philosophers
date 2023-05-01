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

void create_all_philosophers(t_philo **philos, t_params params, int *error);

void init_all_philosophers(t_philo *philos, t_params params, int *error);

void init_one_philo(t_philo *philo, int id, int *error);

void set_all_left_forks(t_philo *philos, t_params params, int *error);

void create_right_fork_for_this_philo(t_philo *philo, int *error);

int	main(int argc, char **argv)
{
	t_params		params;
	t_philo			*philos;
	int 			error;

	error = 0;
	check_args(argc, argv, &error);
	set_global_params_from_args(argv, &params, &error);
	create_all_philosophers(&philos, params, &error);
	init_all_philosophers(philos, params, &error);
//	create_monitor();
//	run_philosophers_and_monitor(philos);
//	clean_up(philos);
//	return(errno);
	return (0);
}


void create_all_philosophers(t_philo **philos, t_params params, int *error)
{
	if (*error)
		return ;
	*philos = malloc(sizeof(t_philo) * (params.nb_philos));
	if(!*philos)
	{
		*error = MALLOC_ERROR;
		error_msg(*error);
	}
}

void init_all_philosophers(t_philo *philos, t_params params, int *error)
{
	int	i;

	if (*error)
		return ;
	i = -1;
	while (++i < params.nb_philos && !*error)
		init_one_philo(&philos[i], i, error);
	set_all_left_forks(philos, params, error);
}

void set_all_left_forks(t_philo *philos, t_params params, int *error)
{
	int	i;

	if (*error)
		return ;
	philos[0].left_fork_mutex = &philos[params.nb_philos].right_fork_mutex;
	i = 0;
	while (++i < params.nb_philos && !*error)
		philos[i].left_fork_mutex = &philos[i - 1].right_fork_mutex;
}

void init_one_philo(t_philo *philo, int id, int *error)
{
	philo->id = id;
	philo->nb_meals_eaten = 0;
	create_right_fork_for_this_philo(philo, error);
}

void create_right_fork_for_this_philo(t_philo *philo, int *error)
{
	*error = pthread_mutex_init(&philo->right_fork_mutex, NULL);
	if (*error != 0)
		return (error_msg(MUTEX_INIT_ERROR));
}

