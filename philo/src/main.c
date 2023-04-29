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

static int	check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_philo	*philosophers = 0;

	(void)philosophers;
	check_args(argc, argv);
//	create_philosophers(philosophers, argv);
//	create_monitor();
//	run_philosophers(philosophers);
//	return(clean_up(philosophers));
	return (0);
}

static int	check_args(int argc, char **argv)
{

	if (argc < 5 || argc > 6)
	{
//		ft_putstr_fd("Bad number of arguments:\n", STDERR_FILENO);
//		ft_putstr_fd("\t./philo number_of_philosophers time_to_die ",
//					 STDERR_FILENO);
//		ft_putstr_fd("time_to_eat time_to_sleep ", STDERR_FILENO);
//		ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n",
//					 STDERR_FILENO);
		return (-1);
	}
	return (0);
}
