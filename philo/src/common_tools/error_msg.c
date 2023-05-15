/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:12:12 by alevra            #+#    #+#             */
/*   Updated: 2023/05/15 14:46:42 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_tools.h"

//display error message depending on the error code
void	error_msg(int code)
{
	printf("Error : \n");
	if (code == INVALID_ARGS)
		printf("invalid arguments.\n");
	if (code == MALLOC_ERROR)
		printf("memory allocation failure.\n");
	if (code == MUTEX_INIT_ERROR)
		printf("mutex initialisation failure.\n");
}
