/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_global_params_from_args.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:10:50 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//this will parse argv to fill philos params
//create the "a_philo_died" mutex
//create the "start_simulation" mutex and lock to prevent philos from beginning
void	set_philos_params_from_args(char **argv, t_philos_params *params,
		int *error)
{
	if (*error)
		return ;
	params->nb_philos = (int)ft_atoll(argv[1]);
	params->time_to_die = (int)ft_atoll(argv[2]);
	params->time_to_eat = (int)ft_atoll(argv[3]);
	params->time_to_sleep = (int)ft_atoll(argv[4]);
	if (argv[5])
		params->nb_of_meals_to_eat = (int)ft_atoll(argv[5]);
	params->a_philo_died = false;
	*error = pthread_mutex_init(&params->a_philo_died_mutex, NULL);
	if (!*error)
		*error = pthread_mutex_init(&params->start_simulation_mutex, NULL);
	if (*error)
	{
		*error = MUTEX_INIT_ERROR;
		return (error_msg(*error));
	}
	pthread_mutex_lock(&params->start_simulation_mutex);
}
