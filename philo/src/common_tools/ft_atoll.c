/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/03 15:08:52 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_tools.h"

static int	ft_isspace(char c);

long long	ft_atoll(const char *str)
{
	long long	result;
	long long	tmp;
	bool		is_negative;

	while (ft_isspace(*str))
		str++;
	is_negative = *str == '-';
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' || *str > '9')
		return (-1);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = result * 10 + *str++ - '0';
		if (tmp < result)
			return (-1);
		result = tmp;
	}
	if (*str != '\0' || is_negative)
		return (-1);
	return (result);
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}
