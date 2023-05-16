/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:15:08 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:48:39 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_state_change(const char *format, t_philo *philosopher,
		t_philos_params *params)
{
	pthread_mutex_lock(&params->a_philo_died_mutex);
	if (params->a_philo_died)
	{
		pthread_mutex_unlock(&params->a_philo_died_mutex);
		return (-1);
	}
	printf(format, get_timestamp(philosopher, get_current_time()), \
			philosopher->id + 1);
	pthread_mutex_unlock(&params->a_philo_died_mutex);
	return (0);
}
