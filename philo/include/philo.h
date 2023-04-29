/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:34:13 by alevra            #+#    #+#             */
/*   Updated: 2023/02/24 16:35:43 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PHILO_H)
#define PHILO_H
# define VALID_ARGS 1
# define INVALID_ARGS -1

struct	s_philo
{
	int number_of_philosophers ;
	int time_to_die ;
	int time_to_eat ;
	int time_to_sleep ;
	int number_of_times_each_philosopher_must_eat ;
	
} typedef t_philo;

int	check_args(int argc, char **argv);

#endif // PHILO_H
