/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:14:46 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:09:00 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_time.h"

struct timeval	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec >= NB_OF_USECONDS_IN_A_SECOND)
	{
		current_time.tv_sec += current_time.tv_usec
			/ NB_OF_USECONDS_IN_A_SECOND;
		current_time.tv_usec %= NB_OF_USECONDS_IN_A_SECOND;
	}
	return (current_time);
}

long long	get_timestamp(const t_philo *philo,
						   const struct timeval current_time)
{
	return ((current_time.tv_sec - philo->start_time.tv_sec)
		* (long long)NB_OF_USECONDS_IN_A_MILLISECOND + (current_time.tv_usec
			- philo->start_time.tv_usec) / NB_OF_USECONDS_IN_A_MILLISECOND);
}

void	timeval_add_ms(struct timeval *tv, const int number_of_ms_to_add)
{
	unsigned long long	new_tv_usec;

	new_tv_usec = tv->tv_usec + (number_of_ms_to_add
			* (long long)NB_OF_USECONDS_IN_A_MILLISECOND);
	if (new_tv_usec >= NB_OF_USECONDS_IN_A_SECOND)
	{
		tv->tv_sec += new_tv_usec / NB_OF_USECONDS_IN_A_SECOND;
		tv->tv_usec = new_tv_usec % NB_OF_USECONDS_IN_A_SECOND;
	}
	else
		tv->tv_usec = new_tv_usec;
}

int	timeval_compare(const struct timeval t1, const struct timeval t2)
{
	if (t1.tv_sec < t2.tv_sec)
		return (-1);
	if (t1.tv_sec > t2.tv_sec)
		return (1);
	if (t1.tv_usec < t2.tv_usec)
		return (-1);
	return (t1.tv_usec > t2.tv_usec);
}

void	sleep_till(const struct timeval goal, const t_philo *philo)
{
	struct timeval	current_time;

	current_time = get_current_time();
	while (timeval_compare(goal, current_time) > 0
		   && all_philos_are_alive(philo->params))
	{
		usleep(5);
		current_time = get_current_time();
	}
}
