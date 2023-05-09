/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:34:13 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:19:41 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_TOOLS_H
# define COMMON_TOOLS_H

# include "philo.h"
# include <stdbool.h>

void		error_msg(int code);
long long	ft_atoll(const char *str);
bool		all_philos_are_alive(t_philos_params *params);
int			print_state_change(const char *format, t_philo *philosopher, t_philos_params *params);
#endif