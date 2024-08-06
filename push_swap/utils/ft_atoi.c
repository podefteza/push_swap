/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:12:38 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/29 12:58:06 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts string to an integer.

#include "../push_swap.h"

int	ft_atoi(const char *nptr)
{
	long long	digit;
	int			signal;

	digit = 0;
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
		digit = (digit * 10) + (*nptr - '0');
		if ((signal == 1 && digit > 2147483647)
			|| (signal == -1 && - digit < -2147483648))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		nptr++;
	}
	return ((int)(digit * signal));
}
