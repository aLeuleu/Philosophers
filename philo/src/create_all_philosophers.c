/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:20:36 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//basic heap allocation
void	create_all_philosophers(t_philo **philos, t_philos_params params,
		int *error)
{
	if (*error)
		return ;
	*philos = malloc(sizeof(t_philo) * (params.nb_philos));
	if (!*philos)
	{
		*error = MALLOC_ERROR;
		error_msg(*error);
	}
}
