/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_philos_are_alive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:15:30 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:46:38 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//returns false if any philo died
bool	all_philos_are_alive(t_philos_params *params)
{
	bool	return_value;

	pthread_mutex_lock(&params->a_philo_died_mutex);
	return_value = params->a_philo_died == false;
	pthread_mutex_unlock(&params->a_philo_died_mutex);
	return (return_value);
}
