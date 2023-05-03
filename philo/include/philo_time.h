/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:15:30 by alevra            #+#    #+#             */
/*   Updated: 2023/05/02 09:15:30 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TIME_H
# define PHILO_TIME_H

# include <sys/time.h>
# include "philo.h"

# define NB_OF_USECONDS_IN_A_SECOND 1000000
# define NB_OF_USECONDS_IN_A_MILLISECOND 1000

struct timeval	get_current_time(void);
long long		get_timestamp(const t_philos_params *params,
							   const struct timeval current_time);
void			timeval_add_ms(struct timeval *tv, const int n);
int				timeval_compare(const struct timeval t1,
								   const struct timeval t2);

#endif //PHILO_TIME_H