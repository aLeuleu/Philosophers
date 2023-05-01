/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_global_params_from_args                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/02/24 16:45:28 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_global_params_from_args(char **argv, t_params *params, int *error)
{
	if (*error)
		return ;
	params->nb_philos = (int)ft_atoll(argv[1]);
	params->time_to_die = (int)ft_atoll(argv[2]);
	params->time_to_eat = (int)ft_atoll(argv[3]);
	params->time_to_sleep = (int)ft_atoll(argv[4]);
	if (argv[5])
		params->meals_to_eat = (int)ft_atoll(argv[5]);
	params->a_philo_died = false;

}