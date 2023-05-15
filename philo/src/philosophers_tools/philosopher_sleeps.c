/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleeps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:15:11 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:51:20 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_sleeps(t_philo *philo)
{
	const struct timeval	current_time = get_current_time();
	struct timeval			time_to_sleep;
	const t_philos_params	*params = philo->params;

	if (print_state_change("%lli\t%i is sleeping\n", philo, philo->params) < 0)
		return (-1);
	time_to_sleep = current_time;
	timeval_add_ms(&time_to_sleep, params->time_to_sleep);
	sleep_till(time_to_sleep, philo);
	return (0);
}
