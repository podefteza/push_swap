/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:12:38 by carlos-j          #+#    #+#             */
/*   Updated: 2024/07/25 16:57:32 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts string to an integer.

#include "../push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	digit;
	int	signal;

	digit = 0;
	signal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = signal * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit = (digit * 10) + (*nptr - '0');
		nptr++;
	}
	return (digit * signal);
}
/* remove comment to test...
int	main(void)
{
	char	*nptr1 = "421337";
	printf("%d\n", ft_atoi(nptr1));
	char	*nptr2 = "-0";
	printf("%d\n", ft_atoi(nptr2));
	char	*nptr3 = "-42";
	printf("%d\n", ft_atoi(nptr3));
	char	*nptr4 = "+42";
	printf("%d\n", ft_atoi(nptr4));
	char	*nptr5 = "+++---++351Porto42";
	printf("%d\n", ft_atoi(nptr5));
	char	*nptr6 = "-2147483648";
	printf("%d\n", ft_atoi(nptr6));
	char	*nptr7 = "2147483647";
	printf("%d\n", ft_atoi(nptr7));
}*/
/*
======= Exemple for the number 421337 =======

digit = 0 * 10 + 52 - 48 = 4
digit = 4 * 10 + 50 - 48 = 42
digit = 42 * 10 + 49 - 48 = 421
digit = 421 * 10 + 51 - 48 = 4213
digit = 4213 * 10 + 51 - 48 = 42133
digit = 42133 * 10 + 55 - 48 = 421337
*/
