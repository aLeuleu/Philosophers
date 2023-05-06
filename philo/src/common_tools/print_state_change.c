/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:15:08 by alevra            #+#    #+#             */
/*   Updated: 2023/04/05 19:38:05 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_tools.h"

int print_state_change(const char *format, t_philo *philosopher, t_philos_params *params)
{
	pthread_mutex_lock(&params->a_philo_died_mutex);
	if (params->a_philo_died)
	{
		pthread_mutex_unlock(&params->a_philo_died_mutex);
		return (-1);
	}
	printf(format, get_timestamp(params, get_current_time()),
		philosopher->id);
	pthread_mutex_unlock(&params->a_philo_died_mutex);
	return (0);
}
