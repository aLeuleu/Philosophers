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

static int	valid_args_count(int argc);
static int	values_are_in_acceptable_limits(char **argv);

int	check_args(int argc, char **argv)
{
	if (valid_args_count(argc) && values_are_in_acceptable_limits(argv))
		return (VALID_ARGS);
	return (INVALID_ARGS);
}

static int	valid_args_count(int argc)
{
	if (argc != 5 && argc != 6)
		return(false);
	return (true);
}

static int	values_are_in_acceptable_limits(char **argv)
{
	long long	tmp;

	errno = 0;
	while (*(++argv))
	{
		tmp = ft_atoll(*argv);
		if (tmp > INT_MAX || tmp < 1)
			return(false);
	}
	if (errno == EINVAL)
		return (false);
	return (true);
}