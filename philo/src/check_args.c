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

#include "check_args.h"

static int	valid_args_count(int argc);
static int	values_are_in_acceptable_limits(char **argv);

//check that there is 5 or 6 args,
//and that there values are in acceptable limits ([1-INT_MAX])
void check_args(int argc, char **argv, int *error)
{
	if (!valid_args_count(argc) || !values_are_in_acceptable_limits(argv))
	{
		*error = INVALID_ARGS;
		error_msg(*error);
	}
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


	while (*(++argv))
	{
		tmp = ft_atoll(*argv);
		if (tmp > INT_MAX || tmp < 1)
			return(false);
	}
	return (true);
}