/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_all_philosophers_threads.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:09:45 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Philos will wait for the "start simulation mutex" to be unlocked.
// If there is a thread creation failure,
// all threads that have already been created will be terminated.
void	start_all_philosophers_threads(t_philo *philos,
									   t_philos_params *params,
									   int *error)
{
	int	i;

	if (*error)
		return ;
	i = -1;
	while (++i < params->nb_philos)
	{
		if (pthread_create(&philos[i].pthread, NULL, &philosopher_thread,
				&philos[i]) != 0)
		{
			*error = THREAD_CREATION_ERROR;
			error_msg(*error);
			break ;
		}
	}
//	if (*error)
	//error handler here
}
