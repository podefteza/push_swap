/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:12:38 by carlos-j          #+#    #+#             */
/*   Updated: 2024/08/28 10:51:41 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts string to an integer.
// v2: changed to "atoll", as it converts to long long int.

#include "../push_swap.h"

long long	ft_atoi(const char *nptr)
{
	long long	number;
	int			signal;

	number = 0;
	signal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = (number * 10) + (*nptr - '0');
		nptr++;
	}
	return (number * signal);
}
