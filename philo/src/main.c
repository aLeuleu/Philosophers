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
	t_philo	*philosophers = 0;

	(void)philosophers;
	if (check_args(argc, argv) != VALID_ARGS)
		return (error_msg(INVALID_ARGS));
//	create_philosophers(philosophers, argv);
//	create_monitor();
//	run_philosophers(philosophers);
//	return(clean_up(philosophers));
	return (0);
}
