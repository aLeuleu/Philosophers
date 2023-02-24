/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/02/24 16:45:28 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo philo_data;

	if (check_argc(argc) < 0)
		return(-1);
	philo_data.number_of_philosophers = argv[0];
	philo_data.time_to_die = argv[1];
	philo_data.time_to_eat = argv[2];
	philo_data.time_to_sleep = argv[3];
	philo_data.number_of_times_each_philosopher_must_eat = 0;
	if (argc == 6)
		philo.number_of_times_each_philosopher_must_eat = argv[4];
	philo(philo_data);


}

static int	check_argc(int argc)
{
	if (argc != 5 || argc != 6)
	{
		ft_printf("Invalid number of arguments\n");
		return (-1);
	}
	return (1);
}
