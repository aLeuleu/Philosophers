/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:30:25 by alevra            #+#    #+#             */
/*   Updated: 2023/02/24 16:43:27 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo( t_philo philo)
{
	log_philo_dat(philo);
}


void log_philo_dat(t_philo philo)
{
	ft_printf("number_of_philosophers : %d\n", philo.number_of_philosophers); //debug
	ft_printf("number_of_times_each_philosopher_must_eat : %s\n", philo.number_of_times_each_philosopher_must_eat); //debug
	ft_printf("time_to_die : %d\n", philo.time_to_die); //debug
	ft_printf("time_to_eat : %d\n", philo.time_to_eat); //debug
	ft_printf("time_to_sleep : %d\n", philo.time_to_sleep); //debug
}
