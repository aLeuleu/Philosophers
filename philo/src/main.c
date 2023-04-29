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

static int	error_msg(int code);

int	main(int argc, char **argv)
{
	t_philo	*philosophers = 0;

	(void)philosophers;
	if (check_args(argc, argv) != VALID_ARGS)
		return (error_msg(INVALID_ARGS));
//	create_philosophers(philosophers, argv);
//	create_monitor();
//	run_philosophers_and_monitor(philosophers);
//	return(clean_up(philosophers));
	return (0);
}

static int	error_msg(int code)
{
	if (code == INVALID_ARGS)
		printf("Pro tip : use valid arguments\n");
	return (code);
}